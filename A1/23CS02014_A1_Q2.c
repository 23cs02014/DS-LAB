#include<stdio.h>
int a[10];
int abs(int x){
        return (x>0)?x:-x;
        }
int main()
{
	for(int i = 0 ; i <    10 ; i++){
	    scanf("%d",&a[i]);
	    }
	    printf("num1:");
	    int num1;
	    scanf("%d",&num1);
	    printf("num2:");
	    int num2;
	    scanf("%d",&num2);
	    int distance=10;
	    for(int i = 0 ; i <10;i++){
	        if(a[i]==num1){
	            for(int j = 0; j < 10 ; j++){
	                if(a[j]==num2){
	                    if(distance > abs(i-j)){
	                        distance = abs(i-j);
	                        }
	                    }
	                }
	            }
	    }
	 printf("distance:%d",distance);   
}