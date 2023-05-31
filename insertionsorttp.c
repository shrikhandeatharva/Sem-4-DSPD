#include <stdio.h>
int main()
{
    int i, size, j, temp = 0;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter an array : \n"); // arr[] = {5,2,1,7,3,8,4}      
    for (i = 0; i < size; i++)     // arr[] = {2,5,1,7,3,8,4}
    {                              // arr[] = {1,2,5,4,3,8,4}
        scanf("%d", &arr[i]);
    }
    printf("Given array is : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    for (i = 1; i < size; i++)
    {
        // a=0;
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j=j-1;
        }
        arr[j + 1] = temp;
    }
    printf("\nSorted array is : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}