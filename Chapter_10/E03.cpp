#include <stdio.h>

int main()
{
  long i, j, c;
  long *ip, *jp, *cp;
  printf("Input 2 numbers:\n");
  scanf("%ld,ld", &i, &j);

  c = i + j;
  ip = &i;
  jp = &j;
  cp = &c;

  //*ip ip指向的数值，增加&输出地址
  printf("&*ip:%ld:%d\n", &*ip,*ip);//输出地址:内容
  printf("&*jp:%ld:%d\n", &*jp,*jp);
  printf("&*cp:%ld:%d\n", &*cp,*cp);

  return 0;
}