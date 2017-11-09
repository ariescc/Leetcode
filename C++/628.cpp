class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		
		sort(nums.begin(), nums.end());
		
		int pro1, pro2;
		
		pro1 = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
		
		pro2 = nums[0] * nums[1] * nums[nums.size()-1];
		
		int res = max(pro1, pro2);
		
		return res;
    }
};