#include <stdio.h>
#include <ctype.h>

int main(){
  FILE *fp;
  char a[60];

    /* opening file for reading */
    fp = fopen("file.txt" , "r");
    if(fp == NULL)
    {
       perror("Error opening file");
       return(-1);
    }
    fgets (a, 60, fp);

    fclose(fp);

  int i ;


  for(i = 0; i < sizeof(a); i++)
        a[i] = toupper(a[i]);

   char key[9]={'V','E','G','I','N','E','R','E','\0'};
   char b[sizeof(a)];
   i = 0;
   int j = 0;
   while(i < sizeof(a)-1){
     if(isalpha(a[i])){

       b[i] = key[j];

     }else {
       b[i] = a[i];

     }
    i++;
    if(j==7){
      j-=7;
    }else
      j++;
   }

//vigenere:
char vigenere[26][26];
int p,q;

for(p=0;p<=25;p++){
  for(q=0;q<=25;q++){
    vigenere[p][q] = 'A'+(p+q)%26;
  }
}

   i = 0;
   int x,y;
   char c[sizeof(a)];
   while(i < sizeof(a)-1){
     if(isalpha(a[i])){
     x = b[i] - 65;
     y = a[i] - 65;
     c[i] = vigenere[x][y];
   }else{
     c[i] = a[i];
   }
     i++;

   }

   for(i=0;i<sizeof(c);i++){

     printf("%c",c[i]);

   }



   return 0;

}
