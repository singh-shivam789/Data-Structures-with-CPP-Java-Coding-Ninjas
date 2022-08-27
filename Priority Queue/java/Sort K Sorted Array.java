/*
Sort K Sorted Array

Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Examples: 
Input : arr[] = {6, 5, 3, 2, 8, 10, 9} k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50} k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}

Time complexity should be O(n * logk) and space complexity should not be more than O(k).

Note: Order of elements in the output is not important.

*/

import java.util.*;
public class Main{
    
    static void sortKSortedArray(int arr[], int k){
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i=0; i<k; i++){
            pQueue.add(arr[i]);
        }
        
        int j=0;
        for(int i=k; i<arr.length; i++){
            arr[j] = pQueue.peek();
            pQueue.remove();
            pQueue.add(arr[i]);
            j++;
        }
        
        while(!pQueue.isEmpty()){
            arr[j++] = pQueue.peek();
            pQueue.remove();
        }
    }
    
    public static void main (String[] args) {
        
        int arr[] = {10,12,15,6,9};
        int k = 3;
        System.out.println(Arrays.toString(arr));
        sortKSortedArray(arr, k);
        System.out.println(Arrays.toString(arr));
    }
}
