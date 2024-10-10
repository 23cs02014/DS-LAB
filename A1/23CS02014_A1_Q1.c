#include <stdio.h>
int main(){
    printf("Type 5 nums:\n");
   int a[5];
   for(int i = 0 ; i < 5 ; i++){
       scanf("%d",&a[i]);
   }
   for(int i = 0 ; i < 5 ; i++){
       int sum = 0;
       for(int j = 0 ; j < 5 ; j++){
           if(i!=j){
               sum+=a[j];
           }
           
       }
       printf("%d ",sum);
   }
   return 0;
}