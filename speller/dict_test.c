#include <string.h>

#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    if (strcasecmp("foo's", "foo") == 0)
        {
            printf("Same");
        }
    else
    {
        printf("not the same")
    }
}