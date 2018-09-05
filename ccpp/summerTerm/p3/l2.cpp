#include <iostream>

using namespace std;

int g = 100;

int main() {
   int a;
   {
     int b;
     b = 20;
     a = 35;
     g = 65;
     cout << b << a << g;
   }
   a = 50;
   cout << a << g << endl;
   return 0;
}
