class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {

            if(nums.front() != val) {
                nums.push_back(nums.front());
            }

            nums.erase(nums.begin());
        }

        return nums.size();
    }
};