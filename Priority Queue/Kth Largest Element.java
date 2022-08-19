/*
Kth largest element

Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.

Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.

Output Format :
The first and only line of output contains the kth largest element

Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec

Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
*/

//O(N*log(k))
import java.util.*;
public class Solution {

    public static int kthLargest(int n, int[] input, int k) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
        for(int i=0; i<k; i++){
            pQueue.add(input[i]);
        }
        for(int i=k; i<input.length; i++){
            if(pQueue.peek() < input[i]){
                pQueue.remove();
                pQueue.add(input[i]);
            }
        }
        return pQueue.peek();
    }
}

/*
Explaination: 
The size of the min heap is k. 
1. replace all the minimum elements by the upcoming greater elements. 
2. at the end of the loop, you'll have a heap containing the k largest elements of the array
3. as the size of the heap is k, and this is a min-heap, k'th largest element IS ALSO THE SMALLEST ELEMENT IN THE HEAP 
4. we can get the K'th largest AKA THE SMALLEST ELEMENT JUST BY ACCESSING THE PEAK OF THE HEAP.
*/
