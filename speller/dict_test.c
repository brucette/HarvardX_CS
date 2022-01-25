#include <stdio.h>

int main(void)
{
    FILE *file = fopen("hi.txt", "r");
    if (file != NULL)
    {
        char buffer[5];
        while (fscanf(file, "%s", buffer) != EOF)
        {
            printf("%s\n", buffer);
        }
        fclose(file);
    }
}
