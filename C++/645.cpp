class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> mp;
        map<int, int>::iterator p;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) {
                res.push_back(nums[i]);
            }
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(!mp[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};