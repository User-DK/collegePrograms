#include <stdio.h>

int main(){
    int n;
    printf("\nEnter the length of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int index=0;
    int max=arr[0];
    
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    int max2;
    if(index==0){
        max2=arr[1];
    }
    else{
        max2=arr[0];
    }
    for(int i=0;i<n;i++){
        if(arr[i]>max2 && i!=index){
            max2=arr[i];
        }
    }
    printf("The Second largest element is: %d",max2);

    return 0;
}