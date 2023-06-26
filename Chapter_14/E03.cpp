#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char fileName[30], str[30];
  printf("Please input file name:\n");
  scanf("%s", fileName);

  if ((fp = fopen(fileName, "w")) == NULL)
  {
    printf("File(%s) is not exists\n", fileName);
    getchar();
    exit(0);
  }

  printf("Put chars:\n");
  getchar();//从stdin流中读入一个字符
  gets(str);
  fputs(str,fp);
  fclose(fp);
  return 0;
}