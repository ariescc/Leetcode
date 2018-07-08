class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> tmp_res; // 每回合结果
        tmp_res.push(0);
        for(int i = 0; i < ops.length(); i++) {
            if(ops[i] > '0' && ops[i] < '9') {
                int cur = ops[i] - '0';
                int first = tmp_res.top();
            }
        }
    }
};