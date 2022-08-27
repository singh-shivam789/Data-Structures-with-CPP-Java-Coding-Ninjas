/*
K largest elements

You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k largest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.

Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :
k largest elements

Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output :
12
16
20
25
*/

import java.util.ArrayList;
import java.util.PriorityQueue;

public class Solution {

    public static ArrayList<Integer> kLargest(int input[], int k) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
        ArrayList<Integer> op = new ArrayList<Integer>();
        for(int i=0; i<k; i++){
            pQueue.add(input[i]);
        }

        for(int i=k; i<input.length; i++){
            int front = pQueue.peek();
            if(front < input[i]){
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
