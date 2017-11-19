class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        for(int i = 0; i < len - 1; i++) {
            if((*nums.begin()) != *(nums.begin() + 1)) {
                nums.push_back(*nums.begin());
            }
            nums.erase(nums.begin());
        }
        nums.push_back(nums.front());
        nums.erase(nums.begin());
        return nums.size();
    }
};