import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Import datetime for logging time of purchase of stock
from datetime import datetime

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    try:
        # Get bought stock
        bought = db.execute(
            "SELECT type, stock, SUM(shares) FROM transactions WHERE user_id = ? AND type = ? GROUP BY stock", session["user_id"], "purchase")

    except RuntimeError:
        return apology("You currently have no stocks to display")
    else:
        # Get sold stock
        sold = db.execute(
            "SELECT type, stock, SUM(shares) FROM transactions WHERE user_id = ? AND type = ? GROUP BY stock", session["user_id"], "sale")
        sold_stocks = []
        for item in sold:
            sold_stocks.append(item["stock"])

        owned_stocks = []
        funds = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        total_value = 0

        # Check if any stocks user bought have also been sold
        for item in bought:
            current_price = lookup(item["stock"])

            if item["stock"] not in sold_stocks:
                # Add info about stock to owned_stocks:
                owned_stocks.append({"stock": current_price["symbol"], "name": current_price["name"],
                                    "price": current_price["price"], "shares": item["SUM(shares)"]})

                total_value += current_price["price"] * item["SUM(shares)"]
            else:
                # Calculate if any of that specific stock still owned
                all_bought = db.execute(
                    "SELECT SUM(shares) FROM transactions WHERE user_id = ? AND stock = ? AND type = ? GROUP BY stock", session["user_id"], item["stock"], "purchase")
                all_sold = db.execute(
                    "SELECT SUM(shares) FROM transactions WHERE user_id = ? AND stock = ? AND type = ? GROUP BY stock", session["user_id"], item["stock"], "sale")
                difference = all_bought[0]["SUM(shares)"] - all_sold[0]["SUM(shares)"]

                if difference > 0:
                    owned_stocks.append(
                        {"stock": current_price["symbol"], "name": current_price["name"], "price": current_price["price"], "shares": difference})

                    total_value += current_price["price"] * difference

        return render_template("index.html", owned_stocks=owned_stocks, funds=funds, total_value=total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # Display a form to enter stock and number of shares
    if request.method == "GET":
        return render_template("buy.html")

    else:
        # Ensure stock symbol was submitted and that it exists
        stock = request.form.get("symbol").upper()
        if not stock or not lookup(stock):
            return apology("must enter valid stock symbol")

        # Ensure valid number of shares entered

        shares = request.form.get("shares")

        try:
            # converting to integer
            int(shares)
        except ValueError:
            return apology("number of shares missing")
        else:
            if not shares or int(shares) <= 0:
                return apology("number of shares missing")

        # Check if user has enough cash
        details = lookup(stock)
        price = details["price"] * int(shares)

        funds = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if funds[0]["cash"] - price < 0:
            return apology("funds exceeded")

        else:
            now = datetime.now()
            purchase = "purchase"

            # Update users transactions
            db.execute("INSERT INTO transactions (type, stock, price, shares, time, user_id) VALUES (?, ?, ?, ?, ?, ?)",
                       purchase, stock, price, shares, now, session["user_id"])

            # Update users amount of cash in users table
            db.execute("UPDATE users SET cash = ? WHERE id = ?", funds[0]["cash"] - price, session["user_id"])

            # Redirect user to home page
            return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    try:
        transactions = db.execute("SELECT type, stock, price, shares, time FROM transactions WHERE user_id = ?", session["user_id"])

    except RuntimeError:
        return apology("You currently have no stocks to sell")

    else:
        return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # Display a form to request a stock quote
    if request.method == "GET":
        return render_template("quote.html")

    # Search for stock user entered and display the result
    else:
        symbol = request.form.get("symbol").upper()

        if not symbol:
            return apology("must enter symbol")

        results = lookup(symbol)

        if not results:
            return apology("stock symbol does not exist")

        else:
            return render_template("quoted.html", results=results)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Display a form so they can register
    if request.method == "GET":
        return render_template("register.html")

    # Check for possible errors
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        verify_password = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("must provide username")

        # Ensure password was submitted
        if not password:
            return apology("must provide password")

        # Ensure password matches verification
        if not verify_password or password != verify_password:
            return apology("password must match verification")

    # Insert new user into USERS table
    hash_password = generate_password_hash(password)

    try:
        # Ensure username not already taken
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_password)
    except ValueError:
        return apology("username is already taken")
    else:
        session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", username)

        # Redirect user to home page
        return redirect("/", 200)


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    try:
        # Make a list of all of stock user has bought, if user has bought any
        bought = db.execute(
            "SELECT type, stock, SUM(shares) FROM transactions WHERE user_id = ? AND type = ? GROUP BY stock", session["user_id"], "purchase")
    except RuntimeError:
        return apology("You currently have no stocks to sell")
    else:
        # Get sold stock
        sold = db.execute(
            "SELECT type, stock, SUM(shares) FROM transactions WHERE user_id = ? AND type = ? GROUP BY stock", session["user_id"], "sale")

        sold_stocks = []
        for item in sold:
            sold_stocks.append(item["stock"])

        user_stocks = []
        actual_shares = {}

        for item in bought:
            # Calculate if any of that specific stock still owned
            if item["stock"] in sold_stocks:
                all_bought = db.execute(
                    "SELECT SUM(shares) FROM transactions WHERE user_id = ? AND stock = ? AND type = ? GROUP BY stock", session["user_id"], item["stock"], "purchase")
                all_sold = db.execute(
                    "SELECT SUM(shares) FROM transactions WHERE user_id = ? AND stock = ? AND type = ? GROUP BY stock", session["user_id"], item["stock"], "sale")
                difference = all_bought[0]["SUM(shares)"] - all_sold[0]["SUM(shares)"]

                if difference > 0:
                    user_stocks.append(item["stock"])
                    actual_shares[item["stock"]] = difference
            else:
                user_stocks.append(item["stock"])
                actual_shares[item["stock"]] = item["SUM(shares)"]

    # Display a form to enter stock and number of shares
    if request.method == "GET":
        return render_template("sell.html", user_stocks=user_stocks)

    else:
        # Ensure stock symbol was submitted and that user owns that stock
        stock = request.form.get("symbol").upper()

        if not stock or stock not in user_stocks:
            return apology("must enter valid stock symbol")

        # Ensure valid number of shares entered
        shares_entered = request.form.get("shares")

        if not shares_entered or int(shares_entered) <= 0 or int(shares_entered) > actual_shares[stock]:
            return apology("invalid number of shares")

        # Check current price of the stock
        details = lookup(stock)
        price = details["price"] * int(shares_entered)
        funds = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        now = datetime.now()
        sale = "sale"

        # Update users transactions
        db.execute("INSERT INTO transactions (type, stock, price, shares, time, user_id) VALUES (?, ?, ?, ?, ?, ?)",
                   sale, stock, price, shares_entered, now, session["user_id"])

        # Increase user's total cash in users table
        db.execute("UPDATE users SET cash = ? WHERE id = ?", funds[0]["cash"] + price, session["user_id"])

        return redirect("/")
