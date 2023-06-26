#include <stdio.h>
#include <stdlib.h>

struct address_list
{
  char name[10];
  char adr[20];
  char tel[15];
} info[100];

void save(FILE *fp, int n)
{
  for (int i = 0; i < n; i++)
  {
    // fwrite(buffer,size,count,fp)
    if (fwrite(&info[i], sizeof(struct address_list), 1, fp) != 1)
    {
      printf("Write failed.");
    }
  }
}

void show(FILE *fp, int n)
{
  for (int i = 0; i < n; i++)
  {
    // read(buffer,size,count,fp)
    fread(&info[i], sizeof(struct address_list), 1, fp);
    printf("%5c %s %s %s\n", i, info[i].name, info[i].adr, info[i].tel);
  }
}

int main()
{
  FILE *fp;
  char fileName[50];
  int n;
  printf("Print studient count:\n");
  scanf("%d", &n);

  printf("Enter file name:\n");
  scanf("%s", fileName);
  if ((fp = fopen(fileName, "w")) == NULL)
  {
    printf("File open failed. press any key to exists.");
    getchar();
    exit(1);
  }

  printf("Print name address mobile\n");
  for (int i = 0; i < n; i++)
  {
    printf("NO%d ", i + 1);
    scanf("%s%s%s", &info[i].name, &info[i].adr, &info[i].tel);
    save(fp, i);
  }

  printf("-----------------------------------------------------\n");
  for (int i = 0; i < n; i++)
  {
    printf("NO%d ", i + 1);
    show(fp, n);
  }
  return 0;
}