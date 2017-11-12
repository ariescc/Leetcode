class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxium = 0;
        int cur = 1;
        int cnt = 0 ;
        for(int i = 0; i < nums.size(); i++) {
            if(cur*nums[i]) cnt++;
            else {
                if(cnt > maxium) maxium = cnt;
                cnt = 0;
                cur = 1;
            }
        }
        if(cnt > maxium) maxium = cnt;
        return maxium;
    }
};