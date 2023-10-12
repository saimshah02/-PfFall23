#include<stdio.h>
int main(){
	int t1=0,t2=1,i,nterm=0;
	
	printf("\nenter the first two terms :");
	scanf("%d %d" ,&t1 ,&t2);
	nterm=t1 +t2;
	
	while(nterm<=10000){
		printf("\n %d" ,nterm);
		t1=t2;
		t2=nterm;
		nterm=t1 + t2;
	}
	return 0;
	
}
