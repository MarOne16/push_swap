#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{   
    int i = 0;
    int j = 0;

    int tmp;
    int x[100];
    while (argv[++i])
        x[i] = atoi(argv[i]);
    while (j < i - 1)
    {
        int k = 0;
        while (k < i - j - 1)
        {
            if (x[k] > x[k + 1])
            {
                tmp = x[k + 1];
                x[k + 1] = x[k];
                x[k] = tmp;
            }
            k++;
        }
        j++;
    }
    i  = 0;
    while (i <= j)
    {
        
        i++;
    }
    return 0;
}
