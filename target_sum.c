#include<stdio.h>

bool target_sum(int arr[],int n,int sum){
int brr[n][sum+1];
for(int i=0;i<=n;i++){
	for(int j=0;j<=sum;j++){
		if(i == 0){
			brr[i][0] = 1;
			brr[i][j] = 0;
		}
		else{
			if(arr[i] == j){
			brr[i][j] = 1;
			}
			else if(brr[i-1][j] == 1){
			brr[i][j] = 1;
			}
			else{
			
			}
			if(j == sum && brr[i][j] == 1){
				return true;
			}
		}
	}
}
}


int main(){
int n;
scanf("%d",&n);
int arr[n+1];
arr[0] = 0;
for(int i=1;i<=n;i++){
scanf("%d",&arr[i]);
}
int sum;
scanf("%d",&sum);
int res = target_sum(arr,n,sum);
printf("%d",res);
return 0;
}
