class Solution {
public:
    int max(int a, int b) {
        if(a > b) return a;
        else return b;
    }
    int findLUSlength(string a, string b) {
        // a b 两个字符串完全相同
        if(a == b) {
            return -1;
        }

        // 两个字符串长度不同，返回字符串较长的长度
        if(a.length() > b.length()) {
            return a.length();
        }
        else {
            return b.length();
        }

        int maxium = -1;
        int cnt = 0;
        // 字符串长度相等的情况
        for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i]) {
                cnt++;
            }
            else {
                maxium = cnt;
                cnt = 0;
            }
        }

        maxium = max(maxium, cnt);
        return maxium;
    }
};