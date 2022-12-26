#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int decimal_to_binary(int decimal) {
//   int digits = 0;
//   int temp = decimal;
//   while (temp > 0) {
//     temp >>= 1;
//     digits++;
//   }
//   char* binary = malloc((digits + 1) * sizeof(char));
//   int index = digits - 1;
//   while (index >= 0) {
//     binary[index] = (decimal & 1) + '0';
//     decimal >>= 1;
//     index--;
//   }
//   binary[digits] = '\0';
//   return (strlen(binary));
// }
int binarysize(int decimal)
{
    int digits = 0;
    while (decimal > 0)
    {
        decimal >>= 1;
        digits++;
    }
    return digits;
}


int main()
{
    printf("%d",decimal_to_binary(9));
    return 0;
}
