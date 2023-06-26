#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char fileName[30], buffer[30];
  printf("Input file name\n");

  scanf("%s", fileName);

  if ((fp = fopen(fileName, "r")) == NULL)
  {
    printf("File(%s) not found\n", fileName);
    exit(0);
  }

  fgets(buffer, sizeof(buffer), fp);

  printf("%s", buffer);

  return 0;
}