class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
		int maxium = max(nums[0], nums[1]);
		int maxci = min(nums[0], nums[1]);
		int cnt = 0;
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i] > maxci && nums[i] < maxium) maxci = nums[i];
			if(nums[i] > maxium) {maxci = maxium; maxium = nums[i];}
			
			
			if(i >= 2 && maxci > nums[i] && i != nums.size()-1 && nums[i-1] > nums[i+1]) return false;
			
			if(nums[i] < nums[i-1]) cnt++;
			if(cnt > 1) return false; 
		}
		
		return true;
		
    }
};