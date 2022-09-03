/*
Code : Staircase using Dp
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274
*/

#include <iostream>
using namespace std;

// Using recursion
long staircase(long n)
{
  if (n < 0)
    return 0;
  else if (n == 0 || n == 1)
    return 1;
  else
  {
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
  }
}

// Using Memoization
long staircase_memoized(long n, long *arr)
{
  if (n < 0)
    return 0;
  else if (n == 0 || n == 1)
    return 1;
  else if (arr[n] != -1)
    return arr[n];
  else
  {
    long ans = staircase_memoized(n - 1, arr) + staircase_memoized(n - 2, arr) + staircase_memoized(n - 3, arr);
    arr[n] = ans;
    return arr[n];
  }
}

// Using Dynamic Programming
long staircase_dp(long n, long *dp)
{
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (long i = 3; i <= n; i++)
  {
    long ans = dp[i - 1] + dp[i - 2] + dp[i - 3];
    dp[i] = ans;
  }
  return dp[n];
}
