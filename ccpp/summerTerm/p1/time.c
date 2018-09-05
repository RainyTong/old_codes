#include <stdio.h>
#include <time.h>

int main(){

  time_t now;

  time(NULL);//same as time(&now);

  printf("%s", ctime(&now));

  return 0;
}
