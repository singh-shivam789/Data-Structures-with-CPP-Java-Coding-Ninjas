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
