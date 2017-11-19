class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        if(!nums.size()) return 0;

        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            dp.push_back(dp[i]);
        }

        int maxium = dp[0];
        for(int i = 0; i < dp.size(); i++) {
            if(dp[i] > maxium) {
                maxium = dp[i];
            }
        }

        return maxium;
    }
};