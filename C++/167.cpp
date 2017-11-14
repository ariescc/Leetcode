class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mp;
        for(int i = 0; i < numbers.size(); i++) {
            mp[numbers[i]] = i + 1;
        }
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++) {
            if(mp[target - numbers[i]] > 0) {
                ans.push_back(i+1);
                ans.push_back(mp[target - numbers[i]]);
                return ans;
            }
        }
    }
};