#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, minus, plus;
    scanf("%lld %lld", &n, &k);
    minus = 1 + k + (2 * (((k - 1) * k / 2) - 1));
    plus = n * ((k * (k + 1)) / 2);
    printf("%lld\n", plus - minus);
    return 0;
}