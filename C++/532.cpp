class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        if(k < 0 || nums.size() == 0) return 0;
        map<int, int> mp, mp1;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            mp1[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(k != 0 && mp[nums[i] + k] > 0 && mp1[nums[i] + k] == mp[nums[i] + k]) {
                cnt++;
                mp[nums[i] + k]--;
            }
            else if(k == 0 && mp[nums[i] + k] > 1 && mp1[nums[i] + k] == mp[nums[i] + k]) {
                cnt++;
                mp[nums[i] + k]--;
            }
        }
        return cnt;
    }
};