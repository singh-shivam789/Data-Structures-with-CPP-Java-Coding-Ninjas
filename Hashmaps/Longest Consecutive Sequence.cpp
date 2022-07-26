/*
128. Longest Consecutive Sequence (Leetcode : Medium)

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4

Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        if(nums.size() <= 1) return nums.size();
        for(auto i:nums) map[i] = 1;
        int longestStreak = 1;
        for(auto i:map){
            if(map.count(i.first-1) == 0){
                int currentStreak = 1, currentElement = i.first;
                while(map.count(currentElement+1) == 1){
                    currentStreak += 1; currentElement += 1;
                } longestStreak = max(currentStreak, longestStreak);
            } } return longestStreak;
    }
};
