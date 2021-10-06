#include <stdio.h>
using namespace std;

int main() {
    int arr[30010][2];
    int mark;
    scanf("%d",&mark);
    int sum = 0;
	int t,i,j,k;
    
	for(i=1;i<=mark;i++)
        arr[i][0]=arr[i][1]=999999;
	// marks the 0 terms
	for(i=1;i*10<=mark;i++) 
        arr[i*10][0]=arr[i*10][1]=0;
	for(i=1;i*16<=mark;i++) 
        arr[i*16][0]=arr[i*16][1]=0;
	for(i=1;i*25<=mark;i++) 
        arr[i*25][0]=arr[i*25][1]=0;
	for(t=1;t<=1100;t++) { // 1100 is somehow arbitrary
		for(i=1;i<=mark;i+=2) {
			// checks if i is a factor of R_t
			for(k=0,j=1;j<=t;j++)
                k=(k*10+1)%i;
			if(k)
                continue;
			for(j=1;j<10;j++) {
				// R_t ~ 9*R_t
				if(j*i>mark)
                    break;
				if(arr[j*i][0]<t)
                    continue;
				if(arr[j*i][1]<j)
                    continue;
				arr[j*i][0]=t; arr[j*i][1]=j;
			}
		}
	}

    for(j=0;j<arr[mark][0];j++)
        sum++;
    if(sum!=0){
        printf("%d ",arr[mark][1]);
        printf("%d",sum);
    }
    else
        printf("0 0");

    return 0;
}