class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int tr[50][50];
        memset(tr, 0, sizeof(tr));
        for(int i = 0; i <= rowIndex; i++) {
            tr[i][0] = 1;
            tr[i][i] = 1;
        }

        if(rowIndex >= 2) {
            for(int i = 2; i <= rowIndex; i++) {
                for(int j = 1; j < i; j++) {
                    tr[i][j] = tr[i-1][j-1] + tr[i-1][j];
                }
            }
        }

        vector<int> res;

        for(int i = 0; i <= rowIndex; i++) {
            res.push_back(tr[rowIndex][i]);
        }

        return res;
    }
};