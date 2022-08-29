#include <iostream>
#include <vector>
using namespace std;

long long int fib_dp(long long int n, long long int arr[])
{
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

long long int fib_recursive(int n)
{
  if (n <= 1)
    return n;
  else
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long int fib_memoized(long long int n, long long int arr[])
{
  if (n <= 1)
    return n;
  else if (arr[n] != -1)
    return arr[n];
  long long int fib_n = fib_memoized(n - 1, arr) + fib_memoized(n - 2, arr);
  arr[n] = fib_n;
  return fib_n;
}

void helper(long long int n)
{
  long long int *arr = new long long int[n + 1];
  for (long long int i = 0; i <= n; i++)
    arr[i] = -1;
  cout << "dp : " << fib_dp(n, arr) << "\n";
  for (long long int i = 0; i <= n; i++)
    arr[i] = -1;
  cout << "memoized : " << fib_memoized(n, arr) << "\n";
  cout << "recursive : " << fib_recursive(n) << "\n";
}

int main()
{
  int n;
  cin >> n;
  helper(n);
}