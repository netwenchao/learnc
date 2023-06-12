#include <stdio.h>

int main()
{
  // Point ++,--
  int i, *p;
  printf("Input i:\n");
  scanf("%d", &i);
  p = &i;

  p--;
  printf("Addr of p-- %x\n", p);
  p++;
  printf("Addr of p   %x\n", p);
  p++;
  printf("Addr of p++ %x\n", p);
  return 0;
}