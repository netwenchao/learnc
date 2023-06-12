#include <stdio.h>

int main(){
  int i=9,j=10;
  int *ip,*jp;
  ip=&i;
  jp=&j;

  if(*ip>*jp){
    printf("Compare with pointer i(%d)>j(%d)",i,j);
  }else{
    printf("Compare with pointer i(%d)<j(%d)",i,j);
  }
  return 0;
}