#include <bits/stdc++.h>
using namespace std;
int climb(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int left = climb(n - 1, dp);
    int right = climb(n - 2, dp);
    return dp[n] = left + right;
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return climb(n, dp);
}

int main()
{
    int n;
    cin >> n;
    climbStairs(n);
}