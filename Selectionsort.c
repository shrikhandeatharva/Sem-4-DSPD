#include<stdio.h>
void main()
{
    int i,size,j,temp=0,temp1=0, min_idx;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter an array : \n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        // Swap the found minimum element with the first element
           if(min_idx != i){
               temp1 = arr[i];
               arr[i] = arr[min_idx];
               arr[min_idx] = temp1;
           }
    }
   
    printf("Sorted array is : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

 // for(i=0;i<size-1;i++){
    //     for(j=i+1;j<size;j++){
    //         if(arr[j]<arr[i]){
    //             temp = arr[i];
    //             arr[i]=arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }