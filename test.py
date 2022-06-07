<form action="/quote" method="post">
        <div class="mb-3">
            <input autocomplete="off" autofocus class="form-control mx-auto w-auto" id="symbol" name="symbol" placeholder="Stock symbol" type="text">
        </div>

        <button class="btn btn-primary" type="submit">Get quote</button>
</form>


{% for key, value in results.items() %}
<tr>
                <td class="left">{{ key }}:</td>
                <td class="right"> {{ value }}</td>
            </tr>
{% endfor %}

  <tbody>
                {% for item in current_prices %}
                    <tr>
                        <td>{{ item["stock"] }}</td>
                        <td>{{ item["SUM(shares)"] }}</td>
                        <td>{{ current_prices[item["stock"]] | usd }}</td>
                        <td>{{ (item["SUM(shares)"] * current_prices[item["stock"]]) | usd }}</td>
                    </tr>
                {% endfor %}
                    <tr>
                        <td></td><td></td>
                        <td>{{ "Cash balance:" }}</td>
                        <td>{{ funds[0]["cash"] | usd }}</td>
                    </tr>
                    <tr>
                        <td></td><td></td>
                        <td><b>{{ "Grand total:" }}</b></td>
                        <td>{{ (total_value + funds[0]["cash"]) | usd }}</td>
                    </tr>
            </tbody>

+------+-------+-------------+
| type | stock | SUM(shares) |
+------+-------+-------------+
| sale | AMZN  | 1           |
| sale | COX   | 3           |
+------+-------+-------------+

+----------+-------+-------------+
|   type   | stock | SUM(shares) |
+----------+-------+-------------+
| purchase | AMZN  | 1           |
| purchase | COX   | 5           |
| purchase | NFLX  | 2           |

current_prices = {}
# Adding to dict:
                # current_prices[current_price["symbol"]] = current_price["price"]
                # CURRENT PRICES: {'AMZN': 2354.32, 'NFLX': 195.62}
+-------+-------------+
| stock | SUM(shares) |
+-------+-------------+
| AMZN  | 1           |
| COX   | 5           |
| NFLX  | 4           |
+-------+-------------+
 transaction_id |   type   | stock |  price  | shares |        time         | user_id |
+----------------+----------+-------+---------+--------+---------------------+---------+
| 1              | purchase | NFLX  | 390.38  | 2      | 2022-05-31 08:18:01 | 1       |
| 2              | purchase | AMZN  | 2302.93 | 1      | 2022-05-31 08:35:06 | 1       |
| 3              | purchase | COX   | 69.54   | 2      | 2022-05-31 08:35:38 | 1       |
| 4              | purchase | COX   | 104.31  | 3      | 2022-05-31 08:35:57 | 1       |
+----------------+----------+-------+---------+--------+---------------------+---------+

CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 10000.00)
CREATE TABLE transactions (transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, type TEXT NOT NULL, stock TEXT NOT NULL, price FLOAT NOT NULL, shares INTEGER NOT NULL, time DATETIME, user_id);
CREATE TABLE purchases (id INTEGER PRIMARY KEY NOT NULL, stock TEXT NOT NULL, price FLOAT NOT NULL, shares INTEGER NOT NULL, time DATETIME);



def index():                                    #4
    """Show portfolio of stocks"""
    try:
        portfolio = db.execute("SELECT type, stock, SUM(shares) FROM transactions WHERE user_id = ? AND type = ? GROUP BY stock", session["user_id"], "purchase")
    except RuntimeError:
        return apology("You currently have no stocks to display")
    else:
        current_prices = {}
        funds = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        total_value = 0

        for item in portfolio:
            current_price = lookup(item["stock"])
            total_value += current_price["price"] * item["SUM(shares)"]
            current_prices[current_price["symbol"]] = current_price["price"]

        return render_template("index.html", portfolio=portfolio, current_prices=current_prices, funds=funds, total_value=total_value)

