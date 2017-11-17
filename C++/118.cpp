class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int tr[100][100];

        for(int i = 1; i <= numRows; i++) {
            tr[i][0] = 1;
            tr[i][i-1] = 1;
        }

        if(numRows >= 3) {
            for(int i = 3; i <= numRows; i++) {
                for(int j = 1; j < i; j++) {
                    tr[i][j] = tr[i-1][j-1] + tr[i-1][j];
                }
            }
        }

        vector<vector<int>> res;

        for(int i = 1; i <= numRows; i++) {
            vector<int> tmp;
            for(int j = 0; j < i; j++) {
                tmp.push_back(tr[i][j]);
            }
            res.push_back(tmp);
        }

        return res;
    }
};