#include <stdio.h>
#include <ctype.h>

int main(){
  int i ;

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

   char c[sizeof(a)];
   for(i = 0; i < sizeof(a)-1; i++){
     if(isalpha(a[i])){
       int num1 = (int)(a[i] - 'A');
       int num2 = (int)b[i];
       int num3 = (int)('Z' - b[i]);
       if(num2 + num1 > 90){
       c[i] = 'A' + (num1 - num3) - 1;
     }else{
       c[i] = b[i] + num1;
     }
     }else{
       c[i] = a[i];
     }
   }

   for(i=0;i<sizeof(c);i++){

     printf("%c",c[i]);

   }

  fp = fopen("f.txt","w");
  fputs(c,fp);
  fclose(fp);



   return 0;
}
