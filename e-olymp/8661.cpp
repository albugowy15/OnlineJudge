#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    double a, p, b, ans, total;
    int k=0; bool stats = 1;
    scanf("%lf %lf %lf", &a, &p, &b);
    while (a > 0 && stats) {
        k++;
        total += (p/100) * a;
        a = (p /100) *a +a;
        if (k%7 == 0) {
            ans = min(a, b);
            a -= ans;
            if (total > b) stats = 0;
            total = 0;
        }
    }

    if (!stats) puts("-1");
    else printf("%d %.2lf", (k/7), ans);
    return 0;
}