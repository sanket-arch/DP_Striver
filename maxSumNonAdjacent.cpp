#include <bits/stdc++.h>

int calc(int n, int nums[], vector<int> &dp) {
  if (n == 0) return nums[0];
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];

  int pick = nums[n] + calc(n - 2, nums, dp);
  int not_pick = calc(n - 1, nums, dp);

  return dp[n] = max(pick, not_pick);
}

int maximumNonAdjacentSum(vector<int> &nums) {

    vector<int> dp(nums.size(),-1);
    
    return calc(nums.size()-1,nums,dp);
}
