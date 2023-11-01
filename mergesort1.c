#include<stdio.h>
int size;

void merge(int arr[],int l,int h,int mid){
    int arr1[size];
    int i,j,k;
    i = l;j = mid+1;k = l;
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            arr1[k] = arr[i];
            i++;
        }
        else{
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=h){
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            arr1[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=l;k<=h;k++){
        arr[k] = arr1[k];
    }
} 

void merge_sort(int arr[],int l,int h){
  if(l<h){
    int mid = (l+h)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,h);
    merge(arr,l,h,mid);
  }
}

int main(){
int arr[] = {5,56,2,89,6,7,90,13}; 
  size = sizeof(arr)/sizeof(arr[0]);
  int low,high;
  low = 0;high = size-1;
  printf("Unsorted array : \n");
  for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
  merge_sort(arr,low,high);

 printf("\nSorted array : \n");
 for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

  return 0;
}
