#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){

    int arr[50],i,target,num;
    
    printf("How any elements do you want in the array ?");
    scanf("%d",&num);

    printf("Enter array elements:\n");
    for(i=0;i<num;i++)
    scanf("%d",&arr[i]);

    printf("Enter elements to search:");
    scanf("%d",&target);

    for(i=0;i<num;i++)
    if(arr[i]==target)

    break;
    if(i<num){

        printf("Target element found at location %d",i);

    }
    else{
        printf("Target element not found in an array");
    }

    return 0;
}