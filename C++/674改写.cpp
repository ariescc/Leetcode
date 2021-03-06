class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		
		if(nums.size() == 0) return 0;
		
		// 存储当前位置结束的最大子序列长度
		int leng[10001];
		for(int i = 0; i < nums.size(); i++) leng[i] = 1;
		
		int maxium = 1;
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i] > nums[i-1]) leng[i] = leng[i-1] + 1;
			if(leng[i] > maxium) maxium = leng[i];
		}
		
		return maxium;
    }
};