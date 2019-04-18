#include<stdio.h>
// array rotation using juggling algorithm O(n) and O(1)

int gcd(int a, int b){
	if (b == 0)
	return a;
	else
	return gcd(b,a%b);
}

void rotate(int arr[],int n, int d){
	int i,k,j,temp;
	
	for (i = 0; i < gcd(n, d); i++ ){
		j = i;
		temp = arr[i];
		while(1){
			k = j + d;
			if(k>=n)
			k-=n;
			if(k==i)
			break;
			arr[j] = arr[k];
			j = k; 
		}
		arr[j] = temp;
	}
}

int main(){
int n,d,i,arr[100000];
printf("enter the array size: ");
scanf("%d",&n);
printf("\nenter the array elements: ");
for(i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
printf("\nenter the rotation size: ");
scanf("%d",&d);

rotate(arr,n,d);

for(i=0;i<n;i++){
printf("%d ",arr[i]);
}

return 0;
}

