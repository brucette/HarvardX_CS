#include <stdio.h>

int main(void)
{
    FILE *file = fopen("hi.txt", "r");
    if (file != NULL)
    {
        char buffer[5];
        fscanf(file, "%s", buffer);
        fclose(file);
        printf("%s\n", buffer);
    }
}
