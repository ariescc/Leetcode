class Solution {
public:
    // s 主串
    // p 模式串
    bool isMatch(string s, string p) {
        int i = 0; // 标记主串指向的位置
        int j = i; // 标记模式串指向的位置
        while(i < s.length()) {
            // 字符不匹配且p[j] != '.'
            if(s[i] != p[j] && p[j] != '.') {
                return false;
            }
            else if(s[i] != p[j] && p[j] == '.') {
                i++;
                j++;
                // .* 匹配任意字符串
                if(p[j] == '*') {
                    if(j == p.length()-1) {
                        return true;
                    }
                    else {
                        // .*a
                        j++;

                    }
                }
            }
            else if(s[i] == p[j]) {
                i++;
                j++;
                // a* 将主串中以a开头的重复子串全部匹配掉
                if(p[j] == '*') {
                    while(s[i] == s[i-1]) {
                        i++;
                    }
                    j++;
                }
            }

            // 如果某个串已经匹配完，而另一个串没有完成匹配，则匹配失败
            if((i == s.length() && j < p.length()) ||
                    (i < s.length() && j == p.length())) {
                return false;
            }

        }
    }
};
