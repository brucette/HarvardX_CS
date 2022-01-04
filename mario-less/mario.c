#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter height of pyramid: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height; )
        {
            printf("#");
        }
        printf("\n");
        j++
    }
}
