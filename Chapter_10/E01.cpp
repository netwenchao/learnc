#include <stdio.h>

int main(){
  int num,*p;
  printf("Input a number:");
  scanf("%d",&num);//读取数字至num中
  p = &num; //指针指向 num所在的地址
  printf("Input is %d and addr is %x\n", num, &num);
  
  printf("Show number using with pointer %d and addr is %x\n", *p, p);
  return 0;
}