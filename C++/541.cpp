class Solution {
public:
    string reverseStr(string s, int k) {
        int cnt = s.length() / (2 * k);
        int lef = s.length() % (2 * k);
        if(cnt > 0) {
            for(int i = 1; i <= cnt; i++) {
                reverse(s.begin()+(i-1)*2*k, s.begin()+(i-1)*2*k + k - 1);
            }
        }
        if(lef >= k) {
            reverse(s.end() - lef + 1, s.end() - lef + k);
        }
        else {
            reverse(s.end() - lef + 1, s.end());
        }
        return s;
    }
};