//比较hash code

void hashCompare(STATE_T* ptr){
//1.数组长度 2.重复比较问题
  for(int i = 0; i < 100; i++){

    for(int j = i+1; j < 100; j++){

      if(strcmp(data[i].hash_code,data[j].hash_code) == 0){
        printf("%s is identical to %s\n", data[i].pathl, data[j].pathl);
      }

  }//j

}//i

}
