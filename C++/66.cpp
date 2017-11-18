class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 如果该数为 0
        if(!digits.size() && !digits[0]) {
            digits[0] = 1;
            return digits;
        }

        /**如果该数大于 0
        [9 9]
        [1 9]
        [1 0]
        [2 0 1]
        */
        vector<int> res;
        digits[digits.size()-1]++;
        for(int i = digits.size()-1; i >= 0; i--) {
            if(i && digits[i] == 10) {
                digits[i] = 0;
                res.push_back(0);
                digits[i - 1]++;
            }
            else if(i && digits[i] != 10) {
                res.push_back(digits[i]);
            }
            else if(!i) {
                if(digits[i] == 10) {
                    digits[0] = 0;
                    res.push_back(0);
                    res.push_back(1);
                }
                else {
                    res.push_back(digits[0]);
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};