/*
Code : Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.

The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12
Sample Output 1 :
3

Explanation of Sample Output 1 :
12 can be represented as :
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

// Using recursion
int minCount(int n)
{
  if (sqrt(n) - floor(sqrt(n)) == 0)
    return 1;
  if (n <= 3)
    return n;

  int ans = n;

  for (int x = 1; x <= n; x++)
  {
    int temp = x * x;
    if (temp > n)
      break;
    else
      ans = min(ans, 1 + minCount(n - temp));
  }
  return ans;
}

// Time Complexity of DP and Memoization -> O(n * sqrt(n));

// Using Memoization
int minCountMemoized(int n, int *arr)
{
  if (sqrt(n) - floor(sqrt(n)) == 0)
    return 1;
  if (n <= 3)
    return n;
  if (arr[n] != -1)
    return arr[n];
  else
  {
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
      int k = i * i;
      if (k > n)
        break;
      else
        ans = min(ans, 1 + (minCountMemoized(n - k, arr)));
    }
    arr[n] = ans;
    return arr[n];
  }
}

// Using DP
int minCountDP(int n)
{
  if (n <= 3)
    return n;
  else if (sqrt(n) - floor(sqrt(n)) == 0)
    return 1;
  int *dp = new int[n + 1];
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i <= n; i++)
  {
    int ans = INT_MAX;
    if (sqrt(i) - floor(sqrt(i)) == 0)
      ans = 1;
    else
    {
      for (int j = 1; j < i; j++)
      {
        int k = j * j;
        if (k > i)
          break;
        else
          ans = min(ans, 1 + dp[i - k]);
      }
    }
    dp[i] = ans;
  }
  return dp[n];
}