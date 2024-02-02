#include<stdio.h>
/*void selectionSort1(int a[],int n){
    int i , j,min,temp;
    for(i = 0; i< n-1 ;i++){
        min = i;
        for(j = i+1 ; j< n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void selectionSort2(int a[],int n){
    int i , j,max,temp;
    for(i = 0; i< n-1 ;i++){
        max = i;
        for(j = i+1 ; j< n;j++){
            if(a[j] > a[max]){
                max = j;
            }
        }
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
}*/
void selectionSort(int a[],int n){
    int i , j , temp , min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    selectionSort(a,n);//Asc Desc
    printf("Elements after sorting:");
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
}