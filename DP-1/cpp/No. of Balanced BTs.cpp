/*
No. of balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 24

Time Limit: 1 sec
Sample Input 1:
3

Sample Output 1:
15

Sample Input 2:
4

Sample Output 2:
315
*/

// Memoized
#include <bits/stdc++.h>
#define MOD % (int)(pow(10, 9) + 7)
using namespace std;

int memoized(int n, int *arr)
{
  if (arr[n] != -1)
  {
    return arr[n];
  }
  int x = (int)(((long)((long)memoized(n - 1, arr) MOD) * ((long)memoized(n - 2, arr) MOD) MOD));
  int y = (int)(((long)((long)memoized(n - 1, arr) MOD) * ((long)memoized(n - 1, arr) MOD) MOD));
  arr[n] = (int)((long)(y + ((long)2 * x MOD)) MOD);
  return arr[n];
}

int balancedBTs(int n)
{
  int *arr = new int[n + 1];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 3;
  for (int i = 3; i <= n; i++)
    arr[i] = -1;
  return memoized(n, arr);
}

// Dynamic Programming
int balancedBTs_DP(int n)
{
  int *arr = new int[n + 1];
  arr[1] = 1;
  arr[2] = 3;
  for (int i = 3; i <= n; i++)
  {
    int x = (int)(long)((long)arr[i - 1] MOD * (long)arr[i - 1] MOD) MOD;
    int y = (int)(long)((long)arr[i - 1] MOD * (long)arr[i - 2] MOD) MOD;
    arr[i] = (int)(long)((long)((long)(2 * y) MOD + x MOD)) MOD;
  }
  return arr[n];
}

int balancedBTs(int n)
{
  if (n <= 1)
    return 1;
  else if (n == 2)
    return 3;
  else
    return balancedBTs_DP(n);
}
