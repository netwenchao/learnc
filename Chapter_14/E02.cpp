#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f;
  char *fileName = "./E01.txt";
  if ((f = fopen(fileName, "r")) == NULL)
  {
    printf("File(%s) open failed.", fileName);
    exit(0);
  }

  char ch;
  while ((ch = fgetc(f)) != EOF)
  {
    printf("%c", ch);
  }

  fclose(f);
  return 0;
}