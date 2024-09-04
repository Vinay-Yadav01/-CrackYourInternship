class Solution {
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind == 0)
            return nums[0];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[ind] + solve(nums, ind - 2, dp);
        int notPick = 0 + solve(nums, ind - 1, dp);
        return dp[ind] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i-2>=0) pick+=dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};