#include <stdio.h>

int main(){
  int sum = 0;
  int i;
  for (i=0; i<5; i++) {
  sum = sum + i;
  if (i < 3) continue;
}
printf("%d\n",sum );
return 0;
}
