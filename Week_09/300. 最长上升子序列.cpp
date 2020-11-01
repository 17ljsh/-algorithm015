class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n,0);
        for (int i = 0; i < n; i++) {
            int temp = 0;
            //往前找比nums[i]小的数，并记录其中最大的上升子序列的长度。
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    temp = max(temp, dp[j]);
                }
            }
            //最终结果为temp + 自身的1
            dp[i] = 1 + temp;
            res = max(res,dp[i]);
        }
        return res;
    }
};