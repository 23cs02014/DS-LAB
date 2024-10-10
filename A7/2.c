#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
int main()
{
    printf("Number of votes:");
    int nvotes;
    scanf(" %d", &nvotes);
    printf("Number of candidates:");
    int ncand;
    scanf(" %d", &ncand);
    printf("Enter votes:");
    int votes[nvotes];
    int count[ncand];
    for(int i = 0 ; i < ncand ; i++){
        count[i]=0;
    }
    for(int i = 0; i < nvotes ; i++){
        scanf(" %d", &votes[i]);
        count[votes[i]]++;
    }
    int max = INT_MIN;
    for(int i = 0 ; i < ncand ; i++){
        if(count[i]>max){
            max = count[i];
        }
    }
    for(int i = 0 ; i < ncand ; i++){
        if(count[i]==max){
            printf("%d",i);
        }
    }
    return 0;
}