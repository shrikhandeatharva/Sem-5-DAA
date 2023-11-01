#include<stdio.h>
int main(){
    int arr[] = {3,5,6,8,90};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0,high = size-1,num;
    printf("Enter the number you want to search : ");
    scanf("%d",&num);

    while(high>=low)
    {
    int mid = (low + (low+high))/2;
        if(arr[mid] == num){
            printf("The number found at index %d",mid);
            break;
        }
        else if(arr[mid]>=num)
        {
            high = mid - 1; 
        }
        else{
            low = mid + 1;
        }
        if(high<low){
            printf("Not found.");
        }
    }
}