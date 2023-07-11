#include <bits/stdc++.h>
using namespace std;

// Memoization
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

// Tabulation
int fib2(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// space optimization
int fib3(int n)
{
    if (n == 0)
        return 0;
    int prev2 = 0;
    int prev = 1;
    int curri = 0;
    for (int i = 2; i <= n; i++)
    {
        curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fib3(n);
}