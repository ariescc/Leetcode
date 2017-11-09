class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
		vector<int> arr;
		arr = nums;
		
		sort(nums.begin(), nums.end());
		
		int sub = -1, sup = -1;
		
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != arr[i])
			{
				sub = i;
				break;
			}
		}
		
		for(int i = nums.size()-1; i >= 0; i--)
		{
			if(nums[i] != arr[i])
			{
				sup = i;
				break;
			}
		}
		
		if(sub == -1 && sub == -1) return 0;
		else return sup - sub + 1;
		
    }
};