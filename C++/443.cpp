#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {

            int cnt = 1, res = 0;

            for(int i = 0; i < chars.size()-1; i++) {


                if(chars[i] == chars[i+1]) {
                    cnt++;
                }
                if((chars[i] != chars[i+1]) || (i == chars.size()-2)) {
                    if(cnt == 1) {
                        res += 1;
                    }
                    else if(cnt > 1 && cnt < 10) {
                        res += 2;
                    }
                    else if(cnt >= 10 && cnt < 100) {
                        res += 3;
                    }
                    else if(cnt >= 100 && cnt < 1000) {
                        res += 4;
                    }
                    else if(cnt == 1000) {
                        res += 5;
                    }
                    cnt = 1;
                }
            }

            if(chars[chars.size()-1] != chars[chars.size()-2]) {
                res += 1;
            }

            return res;
        }
};

int main()
{
    Solution sol;
    int len;
    vector<char> v;

    cin >> len;

    for(int i = 0; i < len; i++) {
        char ch;
        cin >> ch;
        v.push_back(ch);
    }

    cout << sol.compress(v) << endl;

    return 0;
}
