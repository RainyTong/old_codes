#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  // opterr = 0;
  // int a;
  // int b;
  // int i;
  // char* arg1 ;
  // char* arg2 ;


  // while ((a = getopt(argc, argv, "s:i:")) != -1 ){
  //   switch(a){
  //     case 's':
  //       arg1 = optarg;
  //       break;
  //
  //     case 'i':
  //       arg2 = optarg;
  //       int b = atoi(arg2);
  //       printf("%d\n", b);
  //       break;
  //
  //     default:
  //       break;
  //
  //   }
  //
  // }
  //
  // for(i = optind; i < argc ; i++){
  //   printf("%s\n", argv[i]);
  //
  // }

//
//   char array[5000][5000][5000];
//   FILE * fp ;
//   fp = fopen("unidata.txt","r");
//
//   int x = 0;
//   int y = 0;
//   int z = 0;
//   int flag = 0;
//
//   while(fgetc(fp) != EOF){
//
//
//     if(fgetc(fp) == '\"'){
//       !flag;//when a == 1, between quotes;when a == 0, not between quotes
//       array[x][y][z] = '\"';
//       z++;
//     }
//
//
//     if(flag == 0){
//       if(fgetc(fp) == ','){
//         y++;
//         while(fgetc(fp) != ','){
//           array[x][y][z] = fgetc(fp);
//           z++;
//         }
//       }else if(fgetc(fp) == '\"'){
//         !flag;
//         array[x][y][z] = '\"';
//         z++;
//       }else if(fgetc(fp) == '\n'){
//         x++;
//         y = 0;
//         z = 0;
//       }
//     }
//
//     if(flag == 1){
//       if(fgetc(fp) == '\"'){
//         !flag;
//         array[x][y][z] = '\"';
//         z++;
//       }else{
//         while(fgetc(fp) != '\"'){
//           array[x][y][z] = fgetc(fp);
//           z++;
//       }
//       array[x][y][z] = '\"';
//       y++;
//     }
//   }
//
// }
//
// //remove the specific line
//   int counter1;
//   int counter2;
//   int counter3;
//
//   for(counter1 = b-1; counter1 < x+1; counter1++){
//     for(counter2 = 0; counter2 < 5000; counter2++){ //???sizeof(*array)-1
//       for(counter3 = 0; counter3 < 5000; counter3++){ //???sizeof(**array)-1
//         array[counter1][counter2][counter3] = array[counter1+1][counter2][counter3];
//       //  **array++;
//       }
//     //  *array++;
//     }
//   }
//
// //print the specific fields
//   for(i = optind; i < argc ; i++){
//     for(counter1 = 0; counter1 < x; counter1++){
//       for(counter2 = 0; counter2 < 5000; counter2++){ //???
//         printf("%c",array[counter1][i][counter2] );
//       }
//       printf("\n");
//     }
//   }
//
//   fclose(fp);

  return 0;
}
