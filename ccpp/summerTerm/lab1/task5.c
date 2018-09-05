#include <stdio.h>
#include <ctype.h>


int main(){
  FILE *fp;
  char encode[60];

    /* opening file for reading */
    fp = fopen("f.txt" , "r");
    if(fp == NULL)
    {
       perror("Error opening file");
       return(-1);
    }
    fgets (encode, 60, fp);

    fclose(fp);


char key[9]={'V','E','G','I','N','E','R','E','\0'};
char b[sizeof(encode)];
int i = 0;
int j = 0;

while(i < sizeof(encode)-1){
  if(isalpha(encode[i])){

    b[i] = key[j];

  }else {
    b[i] = encode[i];

  }
 i++;
 if(j==7){
   j-=7;
 }else
   j++;
}

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char decode[sizeof(encode)];

for(i = 0; i < sizeof(encode)-1; i++){
  if(isalpha(encode[i])){
    int num1 = (int)encode[i];
    int num2 = (int)b[i];
    int num3 = (int)('Z'-b[i]);
    int num4 = (int)(encode[i] - 'A');

    if(num1 >= num2){

      decode[i] =  'A'+num1-num2;

    }else{
      decode[i] =  'A'+num3+num4+1;

      }
    }else{
      decode[i] = encode[i];
    }

}


for(i=0;i<sizeof(decode);i++){

  printf("%c",decode[i]);

}


return 0;
}
