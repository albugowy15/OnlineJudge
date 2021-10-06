#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int G;
    int N;

    scanf("%d", &G);
    for (int test = 1; test<=G; test++) {
        scanf("%d", &N);
        int arr[3][N];
        for (int i=0; i<N; i++) {
            scanf("%d", &arr[0][i]);
        }
        arr[1][0] = 0;
        arr[2][0] = arr[0][0];

        for (int i=1; i<N; i++) {
            arr[2][i] = arr[0][i] | arr[2][i-1];
            arr[1][i] = arr[2][i] - arr[0][i];
        }

        printf("Game #%d\n", test);
        for (int i=0; i<3; i++) {
            for (int j=0; j<N; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}