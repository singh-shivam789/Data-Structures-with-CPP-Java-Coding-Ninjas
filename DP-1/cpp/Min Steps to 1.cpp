/*
Min Steps to 1

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 10 ^ 6

Time Limit: 1 sec

Sample Input 1 :
4
Sample Output 1 :
2

Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1

Sample Input 2 :
7
Sample Output 2 :
3

Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2
Step 3 : n = 2 / 2 = 1
*/

// Using recursion:
#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>
using namespace std;

int countStepsToOne(int n)
{
  if (n <= 1)
    return 0;
  else
  {
    int ans = countStepsToOne(n - 1);
    if (n % 2 == 0)
      ans = min(ans, countStepsToOne(n / 2));
    if (n % 3 == 0)
      ans = min(ans, countStepsToOne(n / 3));

    return ans + 1;
  }
}

// Using Memoization
int countStepsToOneMemoized(int n, int *arr)
{
  if (n <= 1)
    return 0;
  else
  {
    if (arr[n] != -1)
      return arr[n];
    else
    {
      int x = countStepsToOneMemoized(n - 1, arr), y = INT_MAX, z = INT_MAX;
      if (n % 2 == 0)
        y = countStepsToOneMemoized(n / 2, arr);
      if (n % 3 == 0)
        z = countStepsToOneMemoized(n / 3, arr);

      int ans = min(x, min(y, z));
      arr[n] = ans + 1;
      return arr[n];
    }
  }
}

int countStepsToOne(int n)
{
  int *arr = new int[n + 1];
  for (int i = 0; i <= n; i++)
    arr[i] = -1;
  return countStepsToOneMemoized(n, arr);
}

// Using Dynamic Programming
int countStepsToOneHepler(int n, int arr[])
{
  arr[0] = 0;
  arr[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    int ans = arr[i - 1];
    if (i % 2 == 0)
      ans = min(ans, arr[i / 2]);
    if (i % 3 == 0)
      ans = min(ans, arr[i / 3]);

    arr[i] = ans + 1;
  }
  return arr[n];
}