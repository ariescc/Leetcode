class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int> mp;
        priority_queue<int> heap;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] == 1) heap.push(nums[i]);
        }

        int maxium = heap.top();
        heap.pop();
        heap.pop();

        if(heap.empty()) return maxium;
        else return heap.top();

    }
};