#include <stdio.h>

int main()
{
  // p=f/s
  // p=g*(s*h*ρ)/s
  // p=g*h*ρ
  //  60cm2 h 8cm
  //  103kg/m3 10g/kg
  double a = 10 * 0.08f * 103;
  double *p = &a;
  printf("%.1lf Pa\n", a);
  printf("using pointer(*p)%.1lf Pa", *p);
  printf("using pointer(*&a)%.1lf Pa", *&a);

  return 0;
}