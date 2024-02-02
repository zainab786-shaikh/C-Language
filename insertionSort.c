#include <stdio.h>

/*void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void insertionSort(int a[],int n){
    int i , j , key;
    for(i=1 ;i<n ;i++){
        key = a[i];
        for(j=i-1 ;j>=0 && a[j] > key ;j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
}*/
void insertionSort(int a[],int n){
    int i , j , key;
    for(i=1;i<n;i++){
        key = a[i];
        for(j=i-1;j>=0 && a[j]>key;j--){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}
void main(){
    int a[100],n,i;
    printf("Enter the number of array elements: ");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i = 0; i< n; i++){
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("After sorting:");
    for(i = 0; i< n; i++){
        printf("%d \t",a[i]);
    }
}
