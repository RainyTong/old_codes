#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
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

   int i,j;
   if(optind == argc-1){
     j = 1;
   }else{
   for (i = optind; i < argc-1; i++){

    if(atoi(argv[i]) < atoi(argv[i+1])){
      j = 1;
    }else{
      j = 0;
      break;
    }

  }
}//if meet the order requirement, j = 1; if not meet the requirement, j = 0






    FILE * fp ;
    fp = fopen("unidata.csv","r");

    int flag = 0;
    int line = 1;
    int num1 = 0;
    int num2 = 0;

    char ch;


if(j == 1){
    while(!feof(fp)){
      ch = fgetc(fp);
      if(ch == '\"'){
        !flag;
      }//when a == 1, between quotes;when a == 0, not between quotes


      if(flag == 0){
        if(ch == ','){
          num1++;
        }
         if(ch == '\n'){
          ++line;
          num1 = 0;
          num2 = 0;
          printf("\n"); //change to the next line
        }
      }
      if(line>b){
     for(i = optind; i < argc ; i++){

     if( (num1 == atoi(argv[i])-1) && (ch != ',') ){
        printf("%c",ch );
        num2++;
      }
      if(num1 == atoi(argv[i]) && (ch == ',')){
        for(i = 0; i<(80-num2);i++){
          printf(" ");
        }
        num2 = 0;
      }

  }//end for
 }
}

}else{
    printf("error: the lines you input don't meet the rrequirement(not in a correct order)\n");
    return (-1);
}


  fclose(fp);

  return 0;
}
