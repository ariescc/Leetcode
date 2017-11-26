class Solution {
public:
    bool checkRecord(string s) {
        if(s == "") return false;
        if(s.length() <= 2) {
            if(s[0] == 'A' && s[1] == 'A') return false;
            return true;
        }
        int cnt = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == 'A') cnt++;
            if(i < s.length() - 2) {
                if(s[i] == 'L' && s[i] == s[i+1] && s[i] == s[i+2]) return false;
            }
        }
        if(cnt > 1) return false;
        return true;
    }
};