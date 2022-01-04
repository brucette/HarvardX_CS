#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("What height do you want?");
    }
    while (height < 1 || height > 8);
}