/*#include<stdio.h>
void binarySearch(int a[],int n,int num){
    int left = 0,right = n-1,mid;
    while (left <= right){
        mid = (right + left)/2;
        if(a[mid]==num){
            printf("Element found at index %d",mid);
            return;
        }else if(a[mid] < num){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    printf("Element not found!!!");
}
void main(){
    int a[100],n,i,num;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter number to search:");
    scanf("%d",&num);
    binarySearch(a,n,num);
}*/
#include<stdio.h>
void binarySearch(int a[],int n,int num){
    int left = 0,right = n-1,mid;
    while(left<=right){
        mid = (right + left)/2;
        if(a[mid] == num){
            printf("Number present!!!");
            return;
        }else if(a[mid] < num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    printf("Number not present!!");
}
void main(){
    int a[100],n,i,num;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter number to search:");
    scanf("%d",&num);
    binarySearch(a,n,num);
}