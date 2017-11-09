class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum, res = INT_MIN;
		
		for(int i = 0; i < nums.size(); i++)
		{
			sum = 0;
			if(i + k <= nums.size())
			{
				for(int j = 0; j < k; j++)
				{
					sum += nums[i+j];
				}
				double tmp = sum*1.0 / k;
				res = max(tmp, res);
			}
			
		}
		
		return res;
		
    }
};