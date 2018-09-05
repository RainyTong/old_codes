

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>

void hashCompare(STATE_T** data){
//1.数组长度 2.重复比较问题
  for(int i = 0; i < sizeof(data*); i++){
    for(int j = i+1; j < 100; j++){
      if(strcmp(data*[i].hash_code,data*[j].hash_code) == 0){
        printf("%s is identical to %s\n", data*[i].pathl, data*[j].pathl);
      }
    }
  }
}
