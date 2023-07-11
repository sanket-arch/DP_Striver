#include <bits/stdc++.h>
using namespace std;
// memoization
int jump(int n, vector<int> &dp, vector<int> &heights)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int left = jump(n - 1, dp, heights) + abs(heights[n - 1] - heights[n]);
    // Becauase, we cannot jump everytime.
    int right = INT_MAX;
    if (n > 1)
        right = jump(n - 2, dp, heights) + abs(heights[n - 2] - heights[n]);
    return dp[n] = min(left, right);
}

// tabulation
int jump3(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i - 1] - heights[i]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i - 2] - heights[i]);

        dp[i] = min(left, right);
    }
    // answer always get accumulated at the last index
    return dp[n - 1];
}

// space optimization
int jump4(int n, vector<int> &heights)
{

    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i - 1] - heights[i]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i - 2] - heights[i]);

        prev2 = prev;
        prev = min(left, right);
    }
    // answer always get accumulated at the last index
    return prev;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    // return jump(n-1,dp,heights)
    return jump4(n, heights);
}
