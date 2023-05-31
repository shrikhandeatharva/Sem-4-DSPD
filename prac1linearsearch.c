#include<stdio.h>
void main(){
    int size,num,i,isinarray;
    printf("Enter a number : ");
    scanf("%d",&num);
    int arr[] = {2,4,5,7,89,6,32,4,90};
    size = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<size;i++){
        if(num==arr[i]){
            printf("The number you entered is located at index %d of the array.",i);
            break;
        }
        else if(i==size-1){
            printf("This array does not contain the number you entered.");
        }
    }
}