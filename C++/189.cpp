class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size() - k;
        reverse(nums.begin(), nums.begin() + len);
        reverse(nums.begin() + len + 1, nums.end());
        vector<int> tmp1, tmp2;
        copy(nums.begin(), nums.begin() + len, tmp2.begin());
        copy(nums.begin() + len + 1, nums.end(), tmp1.begin());
        copy(tmp1.begin(), tmp1.begin() + nums.end() - num.begin() - len, nums.begin());
        copy(tmp2.begin(), tmp2.begin() + len, nums.begin() + nums.end() - nums.begin() - len + 1);
    }
};