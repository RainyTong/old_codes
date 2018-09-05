#include <stdio.h>
char name[20];
int studentID;
int main() {
    printf("Please enter your name:\n");
    gets(name);
    printf("Please enter your studentID\n");
    scanf("%d",&studentID);

    printf("Welcome %s%d to the C and C++ world",name,studentID);

    FILE *fp;
    fp = fopen("file.txt","w");
    fprintf(fp,"Welcome %s%d to the C and C++ world",name,studentID);
    fclose(fp);
    return 0;
}
