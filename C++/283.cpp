class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(!nums.front()) {
                cnt++;
                nums.erase(nums.begin());
            }
            else {
                nums.push_back(nums.front());
                nums.erase(nums.begin());
            }
        }
        for(int i = 0; i < cnt; i++) {
            nums.push_back(0);
        }
    }
};