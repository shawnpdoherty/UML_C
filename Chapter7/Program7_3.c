#include <stdio.h>

void printMessage(void)
{
    printf("Programming is fun.\n");
}

int main(void)
{
    int i;
    for (i = 0; i < 5; ++i)
        printMessage();
    return 0;
}