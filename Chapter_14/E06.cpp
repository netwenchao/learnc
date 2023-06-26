#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char i, j, fileName[30];
  printf("Input file name\n");
  scanf("%s", fileName);

  if ((fp = fopen(fileName, "r")) == NULL)
  {
    printf("File not found,press any key to exist.\n");
    getchar();
    exit(0);
  }

  for (i = 0; i < 15; i++)
  {
    fscanf(fp, "%c", &j);
    if (j != EOF)
    {
      printf("Answer is:%5c\n", j);
    }
  }

  fclose(fp);

  return 0;
}