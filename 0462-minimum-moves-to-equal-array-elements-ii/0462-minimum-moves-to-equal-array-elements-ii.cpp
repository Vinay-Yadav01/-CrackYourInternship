class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median =
            n % 2 == 0 ? (nums[n / 2] + nums[n / 2 - 1]) / 2 : nums[n / 2];
        int moves = 0;
        for (int i = 0; i < n; i++) {
            moves += abs(median - nums[i]);
        }
        return moves;
    }
};