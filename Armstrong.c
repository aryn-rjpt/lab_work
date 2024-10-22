#include <math.h>
#include <stdio.h>

int armstrong(int n)
{
    int temp = n, length = 0, sum = 0;

    while (temp != 0)
    {
        temp = temp / 10;
        length++;
    }

    printf("len: %d\n", length);

    temp = n;

    for (int i = 0; i < length; i++)
    {
        int digit = temp % 10;
        temp = temp / 10;
        double val = pow(digit, length);
        sum += val;
    }

    if (sum == n)
        return 1;

    return 0;
}

int main()
{

    int n;
    printf("Enter any number: ");
    scanf("%d", &n);

    if (armstrong(n))
    {
        printf("Yes, it's an Armstrong number");
    }
    else
    {
        printf("No, it's not an Armstrong number");
    }

    return 0;
}
