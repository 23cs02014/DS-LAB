#include<stdio.h>
struct emp {
    int id;
    char name[10];
    float sal;
};
int main()
{
	struct emp emp[3];
	for(int i = 0 ; i <   3 ; i++){
	    printf("id:\n");
	    scanf("%d",&emp[i].id);
	    printf("name:\n");
	    scanf("%s",&emp[i].name);
	    printf("salary:\n");
	    scanf("%f",&emp[i].sal);
	}
	int index = 0;
	if(emp[0].sal > emp[1].sal){
	    if(emp[0].sal>emp[2].sal){
	        index = 0;
	        }
	        else{
	            index = 2;
	        }
	}
	else{
	 	    if(emp[1].sal>emp[2].sal){
	        index = 1;
	        }
	        else{
	            index = 2;
	        }   
	}
	printf("highest salary\nid:%d\nname:%s\nsalary:%f",emp[index].id,emp[index].name,emp[index].sal);
}