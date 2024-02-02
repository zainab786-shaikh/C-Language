/*#include<stdio.h>
void insert(int a[], int num , int index,int n){
    for (int i = n; i >= index; i--){
        a[i+1] = a[i];
    }
    a[index]=num;
    
}
void delete(int a[],int n,int index){
    for(int i=index ;i< n ;i++){
        a[i]= a[i+1];
    }
}
void main(){
    int i ,n, num , a[100],index,choice;
    printf("Enter number of array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter your choice : \n 1.Inserion \n 2.Deletion \n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        printf("Enter the number to insert:");
        scanf("%d",&num);
        printf("Enter its position:");
        scanf("%d",&index);
        insert(a,num,index,n);
        for(i = 0;i < n+1;i++){
            printf("%d \t",a[i]);
        }
        break;
    case 2:
        delete(a,n,index);
        for(i=0;i<n-1;i++){
            printf("%d \t",a[i]);
        }
    default:
        printf("Invalid choioce!!!");
        break;
    }

}*/

#include<stdio.h>

void insert(int a[],int n , int num , int index){
    int i;
    for(i = n; i >= index; i--){
        a[i+1] = a[i];
    }
    a[index] = num;
}
void delete(int a[],int n,int index){
    int i;
    for(i=index; i<n; i++){
        a[i] = a[i+1];
    }
}
void main(){
    int a[100] , n , num , index , i , choice;
    printf("Enter number of array elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter your choice: \n 1.Insert \n2.Delete\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        printf("Enter the number to insert and index:");
        scanf("%d %d",&num,&index);
        insert(a,n,num,index);
        printf("After insertion:");
        for(i=0;i<n+1;i++){
            printf("%d \t",a[i]);
        }
        break;
    case 2:
        printf("Enter he index to delete element:");
        scanf("%d",&index);
        delete(a,n,index);
        printf("After deletion:");
        for(i=0;i<n-1;i++){
            printf("%d \t",a[i]);
        }
        break;
    default:
        printf("Invalid Choice!!!");
        break;
    }

    
}