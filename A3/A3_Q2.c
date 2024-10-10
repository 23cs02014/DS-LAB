#include <stdio.h>
#include <stdlib.h>
#include"test.h"

int main()
{
printf("Enter no of nodes:");
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        printf("enter %d data:",i+1);
        int x;
        scanf("%d",&x);
        insertAtEnd(x);
    }
   printf("values in CLL:");
    printList();

    if(DeleteFirstLast()){
    printf("values after first last delete:");
    printList();
    return 0;
    }
}