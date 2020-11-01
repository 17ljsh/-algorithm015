class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n,0);
        for (int i = 0; i < n; i++) {
            int temp = 0;
            //��ǰ�ұ�nums[i]С����������¼�����������������еĳ��ȡ�
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    temp = max(temp, dp[j]);
                }
            }
            //���ս��Ϊtemp + �����1
            dp[i] = 1 + temp;
            res = max(res,dp[i]);
        }
        return res;
    }
};