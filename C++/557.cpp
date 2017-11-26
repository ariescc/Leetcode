class Solution {
public:
    string reverseWords(string s) {
        // 分割字符串
        string cur = "";
        vector<string> sp;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ')
                cur += s[i];
            else {
                sp.push_back(cur);
                cur = "";
            }
        }
        // 最后一段字符串结尾没有空格，也需要分割
        sp.push_back(cur);

        string res = "";
        // 每段字符串均反转
        for(int i = 0; i < sp.size(); i++) {
            reverse(sp[i].begin(), sp[i].end());
            if(i) {
                res += " ";
            }   
            res += sp[i];
        }

        return res;

    }
};