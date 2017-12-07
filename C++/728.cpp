class Solution {
public:
    bool judgeNum(int n) {
        int num = n;
        while(num) {
            int cur = num % 10;
            if(!cur)
                return false;
            if(cur && n % cur != 0)
                return false;
            num /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;

        for(int i = left; i <= right; i++) {
            if(judgeNum(i))
                res.push_back(i);
        }

        return res;
    }
};