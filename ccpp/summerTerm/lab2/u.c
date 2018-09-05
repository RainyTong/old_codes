#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

  char a[10][10][10] = {{'a','b'},{'c','d'},{'e','f'}};
  int x,y,z;
  int b =1;

  for(x=0;x<3;x++){
    for(y=0;y<3;y++){
      for(z=0;z<2;z++){
        printf("%c",a[x][y][z] );
      }

    }
    printf("\n");
  }

  for(x=b-1;x<3;x++){
    for(y=0;y<3;y++){
      for(z=0;z<2;z++){
        a[x][y][z]=a[x+1][y][z];
      }
    }
  }

  for(x=0;x<3;x++){
    for(y=0;y<3;y++){
      for(z=0;z<2;z++){
        printf("%c",a[x][y][z] );
      }

    }
    printf("\n");
  }

  return 0;
}
