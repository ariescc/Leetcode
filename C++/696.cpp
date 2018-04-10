/*
 * -------------------- 我是题解 -----------------------
 *
 * 寻找子串，满足子串中字符0和字符1的个数相等。并且字符0和字符1要在子串中相邻。0101不满足要求。
 *
 * 从头开始遍历，计数有多少个字符0，当下一个字符是1的时候，由于前面有3个0相邻，所以之后有至多三种子串，即
 * 00010,000110， 0001110。遍历到下一位的时候给字符1计数，如果当前字符1的个数小于3，则该情况满足。
 *
 * 时间复杂度：O(n)
*/

class Solution {
    public:
        int countBinarySubstrings(string s) {
            int res = 0; // result
            int zero = 0, one = 0, flag = 0;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '0') {
                    if(flag) {
                        zero = 0;
                        flag = 0;
                    }
                    zero++;
                    if(one >= zero && one && zero) {
                        res++;
                    }
                }
                else {
                    if(!flag) {
                        one = 0;
                        flag = 1;
                    }
                    one++;
                    if(zero >= one && one && zero) {
                        res++;
                    }
                }
            }
            return res;
        }
};
