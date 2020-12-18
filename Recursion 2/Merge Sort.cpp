// Merge Sort Code
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.

// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)

// Output format :
// Array elements in increasing order (separated by space)

// Constraints :
// 1 <= n <= 10^3

// Sample Input 1 :
// 6 
// 2 6 8 5 4 3

// Sample Output 1 :
// 2 3 4 5 6 8

// Sample Input 2 :
// 5
// 2 1 5 2 3

// Sample Output 2 :
// 1 2 2 3 5 

#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e) / 2;
    int temp[1000] = {0};
    int i,j,k;
    i = s;
    j = mid+1; 
    k = s;
    while(i<=mid && j<=e){
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int l=s; l<=e; l++) arr[l] = temp[l];
    return;
}
void helper(int arr[], int s, int e){
    if(s >= e) return;
    else{
        int mid = (s + e) / 2;
        helper(arr, s, mid);
        helper(arr, mid+1, e);
        merge(arr, s, e);
    }
}
void mergeSort(int input[], int size){
    return helper(input, 0, size-1);
}

int main() {
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}
