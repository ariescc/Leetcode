class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        while(pos < s.size()) {
            if(pos + k > s.size()) {
                k = s.size() - pos;
            }
            string tmpStr = s.substr(pos, k);
            reverse(tmpStr.begin(), tmpStr.end());
            s.replace(pos, k, tmpStr);
            pos += 2 * k;
        }
        return s;
    }
};