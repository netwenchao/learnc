/*
数据变量存储第一个元素地址;
变量+/-1移动至上/下一个元素;
*/
#include <stdio.h>

int main()
{
  int *pa, *pb, a[2], b[2];
  pa = &a[0];
  pb = b;
  printf("Input a\n");

  for (int i = 0; i < 2; i++)
    scanf("%d", &a[i]);

  printf("Input b\n");

  for (int i = 0; i < 2; i++)
    scanf("%d", pb + i);

  printf("========a=========\n");
  for (int i = 0; i < 2; i++)
    printf("%d", a[i]);

  printf("\n========b=========\n");
  for (int i = 0; i < 2; i++)
    printf("%d", b[i]);

  return 0;
}