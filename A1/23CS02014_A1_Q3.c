#include<stdio.h>

int main()
{
	int size1,size2;
	printf("size1:");
	scanf("%d",&size1);
	int	a1[size1];
	printf("enter a1 array:");
	for(int i = 0 ; i<size1;i++){
	    scanf("%d",&a1[i]);
	    }
	printf("size2:");
	scanf("%d",&size2);
	int	a2[size2];
		printf("enter a2 array:");
	for(int i = 0 ; i<size2;i++){
	    scanf("%d",&a2[i]);
	    }


printf("intersection:\n");
for(int i = 0 ; i < size1 ; i++){
    for(int j = 0 ; j < size2 ; j++){
        if(a1[i]==a2[j]){
            printf("%d ",a2[j]);
        }
        }
    }
    printf("\nunion:\n");

    
}