#include <stdio.h>

int func(int n) {
    int s, d;

    if (n!=0) {
      d = n%10;
      n = n/10;
      s = d + func(n);
    } else {
      return 0;
    }
    return s;
}

int main() {
    int a = func(123);
    printf("%d\n", a);
    return 0;
}
