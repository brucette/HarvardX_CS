#include <stdio.h>
#include <cs50.h>

int main(void)
{
    do
    {
        int height = get_int("Enter height of pyramid: ");
    }
    while (height < 1 || height > 8);
}
