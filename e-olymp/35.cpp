#include <iostream>
#include <math.h>
using namespace std;

int main(){
long long a, num, b, n;
scanf("%lld", &n);
num= 2 * ceil((double)(n+sqrt(6.0*n))/2)-n;
a = (3*n + num)/2;
printf("%lld\n", a);
}