/*#include<stdio.h>
void linearSearch(int a[],int n , int num){
    int i , flag= 0;
    for(i = 0;i<n;i++){
        if(a[i]==num){
            printf("Element found at index %d ",i);
            flag = 1;
            return;
        }
    }
    printf("Element not found!!!");
}
void main(){
    int a[100],n,i,num;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number to search:");
    scanf("%d",&num);
    linearSearch(a,n,num);
}*/

#include <stdio.h>
void linearSearch(int a[],int n,int num){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(a[i] == num){
            printf("Number found!!!");
            return;
        }
    }
    printf("Number not found!!!");
}
void main(){
    int i , n , a[100],num;
    printf("Enter number of array elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter number to search:");
    scanf("%d",&num);
    linearSearch(a,n,num);
}