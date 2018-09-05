#include <stdio.h>

char vigenere[26][26];
int i,j;

int main(){

  for(i=0;i<=25;i++){
    for(j=0;j<=25;j++){
      vigenere[i][j] = 'A'+(i+j)%26;
    }
  }

  for(i=0;i<=25;i++){
    for(j=0;j<=25;j++){
      printf("%c", vigenere[i][j]);
    }
    printf("\n");
  }

  return 0;


}
