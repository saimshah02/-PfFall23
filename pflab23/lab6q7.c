#include<stdio.h>
int main(){
	int n,i;
	printf("\nenter length of array :");
	scanf("%d" ,&n);
	 int a[n];
	 
	 for(i=0 ;i<n ;i++){
	 	printf("\nenter element no %d :" ,i);
	 	scanf("%d" ,&a[i]);
	 }
	 for(i=0 ;i<n ;i++){
	 	printf("\n %d " ,a[i]);
	 }
	 return 0;
}
