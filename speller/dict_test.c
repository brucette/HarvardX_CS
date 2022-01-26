#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main(void)
{
    if (strcasecmp("ca", "cat") == 0)
        {
            printf("Same\n");
        }
    else
    {
        printf("not the same\n");
    }
}