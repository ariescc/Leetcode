#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0;
        bool flag = false; // true 表示进1
        string res = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while(i < a.length() && i < b.length()) {
            if(a[i] == b[i] && a[i] == '1') {
                // 当前需要进1位
                if(flag) {
                    res += "1";
                }
                else {
                    res += "0";
                    flag = true; // 进1位
                }
            }
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
                if(flag) {
                    res += "0";
                }
                else {
                    res += "1";
                }
            }
            else if(a[i] == b[i] && a[i] == '0') {
                if(flag) {
                    res += '1';
                    flag = false;
                }
                else {
                    res += '0';
                }
            }
            i++;
        }

        if(a.length() > b.length()) {
            while(i < a.length()) {
                if(a[i] == '1') {
                    if(flag) {
                        res += '0';
                    }
                    else {
                        res += '1';
                        flag = false;
                    }
                }
                else {
                    if(flag) {
                        res += '1';
                        flag = false;
                    }
                    else {
                        res += '0';
                    }
                }
                i++;
            }
        }
        else if(a.length() < b.length()) {
            while(i < b.length()) {
                if(b[i] == '1') {
                    if(flag) {
                        res += '0';
                    }
                    else {
                        res += '1';
                        flag = false;
                    }
                }
                else {
                    if(flag) {
                        res += '1';
                        flag = false;
                    }
                    else {
                        res += '0';
                    }
                }
                i++;
            }
        }

        if(flag) {
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution sol;

    string a1, a2;

    cin >> a1;
    cin >> a2;

    cout << sol.addBinary(a1, a2) << endl;

    return 0;

}
