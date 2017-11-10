class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int need = r * c;
        int have = nums.size() * nums[0].size();
        int k = 0, p = 0;
        int cnt = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        if(need > have) return nums;
        else {
            for(int i = 0; i < nums.size(); i++) {
                for(int j = 0; j < nums[0].size(); j++) {
                    temp.push_back(nums[i][j]);
                    cnt++;
                    if(cnt == c) {
                        ans.push_back(temp);
                        temp.clear();
                        cnt = 0;
                    } 
                    p++;
                }
            }
            return ans;
        }
    }
};