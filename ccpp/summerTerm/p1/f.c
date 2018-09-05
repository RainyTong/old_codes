#include <stdio.h>

int main () {
   char cha[] = "abcd";
   char *chars = cha ;
   printf("%c",*chars++); //a
   printf("%c",((*chars)++));//b
   printf("%c",*(chars++));//c
   printf("%c",*chars);//c
   return 0;
}
