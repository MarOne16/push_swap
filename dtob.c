#include <stdio.h>

void decimal_to_binary(int decimal_number) {
  if (decimal_number == 0) {
    printf("0");
    return;
  }
  int binary_number[32];
  int i = 0;
  while (decimal_number > 0) {
    binary_number[i] = decimal_number % 2;
    decimal_number = decimal_number / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary_number[j]);
  }
}

int main(void)
{
  int decimal_number = 5;
  decimal_to_binary(decimal_number);
  printf("\n");
  decimal_number = 2;
  decimal_to_binary(decimal_number);
    printf("\n");
    decimal_number = 42;
  decimal_to_binary(decimal_number);
    printf("\n");
  decimal_number = 11;
  decimal_to_binary(decimal_number);
    printf("\n");
  decimal_number = 21;
  decimal_to_binary(decimal_number);
  return 0;
}