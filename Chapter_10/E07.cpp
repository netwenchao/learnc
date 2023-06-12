/*
二维数组
*/
#include <stdio.h>

int main()
{
  int a[3][5], i, j;
  printf("Input numbers:\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  printf("\n");

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 5; j++)
    {
      printf("%d(%x)   ", a[i][j], &a[i][j]);
    }
    printf("\n");
  }
  return 0;
}