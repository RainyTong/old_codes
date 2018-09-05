#include <stdio.h>
#include <string.h>
int main(){
char s[10] = "Hello";
char *p = s;
int i;
for (i=0; i < strlen(s); i+) {
putchar(toupper((*p)++)); }
putchar('\n');
printf("%s\n", s);
return 0;
}
