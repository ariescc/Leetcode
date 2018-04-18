#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void get_next(string str, vector<int>& next, int len)
    {
        next[0] = -1;
        int k = -1;

        for(int q = 1; q < len; q++) {
            while(k > -1 && str[k+1] != str[q]) {
                k = next[k];
            }

            if(str[k+1] == str[q]) {
                k = k + 1;
            }

            next[q] = k;
        }

    }

    int strStr(string haystack, string needle) {
        // kmp算法
        int hlen = haystack.length();
        int nlen = needle.length();

        if(hlen == 0 && nlen == 0) {
            return 0;
        }
        else if(hlen != 0 && nlen == 0) {
            return 0;
        }
        else if(hlen == 0 && nlen != 0) {
            return -1;
        }

        int k = -1;

        vector<int> next(nlen, -1);

        get_next(needle, next, nlen);

        for(int i = 0; i < hlen; i++) {

            while(k > -1 && haystack[i] != needle[k+1]) {
                k = next[k];
            }

            if(haystack[i] == needle[k+1]) {
                k = k + 1;
            }

            if(k == nlen - 1) {
                return i - nlen + 1;
            }

        }

        return -1;

    }
};

int main()
{
    Solution sol;
    string str1, str2;

    cin >> str1;
    cin >> str2;

    cout << sol.strStr(str1, str2) << endl;

    return 0;
}
