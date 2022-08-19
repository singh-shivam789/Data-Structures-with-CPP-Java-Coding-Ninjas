/*
K smallest Elements

You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(n * logk) and space complexity should not be more than O(k).

Note: Order of elements in the output is not important.

Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.

Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 

Constraints:
Time Limit: 1 sec

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output 1 :
1 2 3 5 
*/

import java.util.*;

public class Solution {

	public static ArrayList<Integer> kSmallest(int n, int[] input, int k) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>(Collections.reverseOrder());
        ArrayList<Integer> op = new ArrayList<Integer>();
        for(int i=0; i<k; i++){
            pQueue.add(input[i]);
        }
        
        for(int i=k; i<input.length; i++){
         	int front = pQueue.peek();
            if(front > input[i]){
                pQueue.remove();
                pQueue.add(input[i]);
            }
        }
        
        while(!pQueue.isEmpty()){
        	op.add(pQueue.peek());
            pQueue.remove();
        }
        return op;
	}
}
