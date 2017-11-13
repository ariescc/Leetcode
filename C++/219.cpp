class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 1; i <= k; i++) {
            if(nums[i] == nums[0]) return true;
        }

        for(int i = 1; i < nums.size(); i++) {
            if(!mp[nums[i]]) mp[nums[i]] = i;
            else {
                if((i - mp[nums[i]]) <= k) return true;
            }
        }

        return false;
    }
};