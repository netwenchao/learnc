#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f;
  char *fileName = "./E01.txt";
  //打开文件,不存在则创建
  if ((f = fopen(fileName, "w+")) == NULL)
  {
    printf("File(%s) is not exists.", fileName);
    exit(0);
  }

  char ch;
  while ((ch = getchar()) != '#')
  {
    //将字符输出到磁盘文件
    fputc(ch, f);
  }

  fclose(f);
  return 0;
}