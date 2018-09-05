#ifndef COMPARE
#define COMPARE
#include"compare.h"
#endif

extern struct structure1 data[MAX_LINE];

//declare a method to compare files according to the hashcode
void compare(char* dir, int size) {
	int i ;
	int j ;
	char* dir2 = dir;

	for(i = 0 ; i < size ; i++){

			for(j = i+1; j<=size ; j++){
				//distinguish wether two file's hash code are same
				if(strcmp(data[i].hash_code,data[j].hash_code) == 0){
					char* data1_ptr = data[i].namel;
					char* data2_ptr = data[j].namel;

					//delate the same part of the path of the file with the path user entered
					while (*dir == *data1_ptr) {
						dir++;
						data1_ptr++;
					}
					
					//delate the same part of the path of the file with the path user entered
					while (*dir2 == *data2_ptr) {
						dir2++;
						data2_ptr++;
					}

					printf(".%s is identical to .%s\n", data1_ptr, data2_ptr);
				}
			}
	}

}


// int main(){
//   data[0].hash_code = "903bb5bfa491d17bcb4dede463f4c9fc73840681";
//   data[0].pathl = "/get_hashcode.h";
//   data[0].namel = "get_hashcode.h";
//   data[1].hash_code = "903bb5bfa491d17bcb4dede463f4c9fc73840681";
//   data[1].pathl = "/get_hcode.h";
//   data[1].namel = "get_hashcoe.h";
//   hashCompare;
//   return 0 ;
// }
