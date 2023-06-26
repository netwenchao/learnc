#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char fileName[30], buffer[30];
  int i = 1, j = 2;
  printf("Input file name\n");

  scanf("%s", fileName);

  if ((fp = fopen(fileName, "w")) == NULL)
  {
    printf("File(%s) not found,press any key to exit.\n", fileName);
    getchar();
    exit(0);
  }

  fprintf(fp, "%4d\n", i); //写入fp所指的磁盘文件中
  fprintf(fp, "%2d", i);
  fprintf(fp, "%4d\n", i);
  fprintf(fp, "%d", i);
  fprintf(fp, "%3d", j);
  fprintf(fp, "%4d", i);
  fclose(fp);

  return 0;
}