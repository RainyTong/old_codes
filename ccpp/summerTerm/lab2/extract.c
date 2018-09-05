#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  opterr = 0;
  int a;
  int b;
  char* arg1 ;
  char* arg2 ;

  while ((a = getopt(argc, argv, "s:i:")) != -1 ){
    switch(a){
      case 's':
        arg1 = optarg;
        break;

      case 'i':
        arg2 = optarg;
        int b = atoi(arg2);
        break;

      default:
        break;

    }

  }

  int i;
/*  for(i = optind; i < argc ; i++){
    printf("%s\n", argv[i]);

  }//列数： argv[optind]-argv[argc-1]
*/
    FILE * fp ;
    fp = fopen("unidata.txt","r");

    int flag = 0;
    int line = 1;
    int num = 0;

    char ch;

    while(!feof(fp)){
      ch = fgetc(fp);
      if(ch == '\"'){
        !flag;
      }//when a == 1, between quotes;when a == 0, not between quotes


      if(flag == 0){
        if(ch == ','){
          num++;
        }else if(ch == '\n'){
          line++;
          num = 0;
          printf("\n"); //change to the next line
        }
      }
    for(i = optind; i < argc ; i++){
      if((line>b) && (num == atoi(argv[i]-1))){
        printf("%c",ch );
      }

  }


}

  fclose(fp);

  return 0;
}
