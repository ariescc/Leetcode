class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int> nums) {
        if(nums.empty()) {
            return;
        }
        else {
            dp.push_back(nums[0]);
            int len = nums.size();
            for(int i = 1; i < len; i++) {
                dp.push_back(dp[i - 1] + nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if(!i) {
            return dp[j];
        }
        else {
            return dp[j] - dp[i - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */