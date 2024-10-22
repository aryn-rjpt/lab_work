#include <stdlib.h>
#include <stdio.h>

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move 1 from %c to %c\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, aux, to);
        printf("Move %d from %c to %c\n", n, from, to);
        hanoi(n - 1, aux, to, from);
    }
}

int main()
{
    int n = 3;
    char from = 'A';
    char to = 'B';
    char via = 'C';
    // calling hanoi() method
    hanoi(n, from, via, to);
}