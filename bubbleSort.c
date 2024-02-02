#include<stdio.h>
/*void bubbleSort(int a[],int n){
    int i,j,temp;
    for(i = 0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}*/
void bubble(int a[] , int n){
    int i , j,temp;
    for(i =0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void main(){
    int n , a[100],i;
    printf("Enter the number of array elemens:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i = 0;i < n; i++){
        scanf("%d",&a[i]);
    }
    bubble(a,n);
    printf("Elements after sorting:");
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
}