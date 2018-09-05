#include "lab3_main.h"

struct structure1 data[MAX_LINE];

using namespace std;

int main()
{
    int i = 0 ;  //create a variable to calculate the number of files
    char p[MAX_LINE];

    cout<<data[0].pathl;
    char *q = p ;
    cout << "please enter a path: " << endl;
    cin >> p;

    listDir(p); //call the method , scan the directory

    //calculate the number of files
    while(data[i+1].namel[0]!='\0'){
      i++;
    }
    printf("%d\n",i+1 );
    //call the method , get the hashcode of the files
    get_Hashcode(i+1);

    //compare every file according to the hashcode
    compare(q,i);

    return 0;
}
