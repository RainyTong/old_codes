#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct{
  int a;
}STRUCT_T;

int main ()
{
  int my_int = 1;

  int* intp = (int*)malloc(sizeof(int));

  STRUCT_T var ;
  STRUCT_T* strp = (STRUCT_T*)malloc(sizeof(STRUCT_T));

}
