#include <stdio.h>

void interchange(int n,int *arr1,int *arr2){
    int x=0;
    for(int i=0;i<n;i++){
        x=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=x;
    }
    printf("\nArray1: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }
    printf("\nArray2: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }
}

int main(){
    printf("\nEnter the Number of elements in the Arrays: ");
    int n;
    scanf("%d",&n);
    int narr1[n],narr2[n];
    printf("\nEnter the Array1:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&narr1[i]);
    }
    printf("\nEnter the Array2:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&narr2[i]);
    }
    interchange(n,narr1,narr2);
    return 0;
}