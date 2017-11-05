class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
		map<int, int> mmp;
		
		// 统计每个element出现的次数
		for(int i = 0; i < nums.size(); i++)
		{
			mmp[nums[i]]++;
		}
		
		map<int, int>::iterator p;
		
		int maxium = -1;
		
		// 找到出现次数最多element的次数
		for(p = mmp.begin(); p != mmp.end(); p++)
		{
			if(p->second > maxium) maxium = p->second;
		}
		
		vector<int> arr;
		
		// 寻找到出现次数最多的所有element
		for(p = mmp.begin(); p != mmp.end(); p++)
		{
			if(p->second == maxium) arr.push_back(p->first);
		}
		
		int result[50000], k = 0;
		for(int i = 0; i < arr.size(); i++)
		{
			int front, back;
			for(int j = 0; j < nums.size(); j++)
			{
				if(nums[j] == arr[i]) 
				{
					front = j;
					break;
				}
			}
			for(int j = nums.size()-1; j >= 0; j--)
			{
				if(nums[j] == arr[i])
				{
					back = j;
					break;
				}
			}
			result[k++] = back - front; // 求出每个element的子串长度
		}
		
		sort(result, result + k);
		
		return result[0] + 1;
    }
};