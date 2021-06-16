#include<bits/stdc++.h>
using namespace std;

/*
Prints the array
*/
void print(int* arr, int len){
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

/*
Merges the left and right part of the array & sorts it
*/

int* merge(int *arr, int low, int mid, int high){

    int leftLength = mid-low+1;
    int rightLength = high-mid;

    int* left = new int[leftLength];
    int* right = new int[rightLength];

    for(int i=0;i<leftLength;i++){
        left[i] = arr[low + i];
    }

    cout<<"Left of lenght :"<<leftLength<<" : ";
    print(left, leftLength);

    for(int i=0;i<rightLength;i++){
        right[i] = arr[mid + 1 + i];
    }

    cout<<"Right :";
    print(right, rightLength);

    int i=0, j=0, k=low;

    while(i < leftLength && j < rightLength){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while(i < leftLength) arr[k++] = left[i++];

    while(j < rightLength) arr[k++] = right[j++];

    cout<<"Sorted: ";
    for(int s = low; s<=high;s++) cout<<arr[s]<<" ";
    cout<<endl;

    return arr;
}

/*
Splits the array into left and right part
*/

int* mergeSort(int* arr, int low, int high){
    if(low >= high)
        return arr;
    int mid = low + (high - low)/2;
    cout<<low<<" "<<mid<<" "<<high<<endl;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    return merge(arr, low, mid, high);
}



int main(){
    int arr[10] = {6,4,1,2,8,5,3,7,0,9};
    cout<<"Before Sorting: ";
    print(arr, 10);
    
    int* a = mergeSort(arr, 0, 9);
    cout<<"After Sorting: ";
    print(arr, 10);
    return 0;
}