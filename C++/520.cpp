class Solution {
public:
    bool detectCapitalUse(string word) {
        // 字符长度为1， 一定为正确
        if(word.length() == 1) {
            return true;
        }

        // 字符串的所有字符全为小写，正确
        // 第一个字符为小写的话，如果之后所有的字符均为小写，返回true，否则返回false
        if(islower(word[0])) {
            for(int i = 1; i < word.length(); i++) {
                if(isupper(word[i])) return false;
            }
            return true;
        }
        else {
            // 如果第一个字符为大写的，如果之后的字符全是大写或者全是小写，则返回true，否则返回false
            bool hav_low = false;
            bool hav_up = false;
            for(int i = 1; i < word.length(); i++) {
                if(islower(word[i])) {
                    cout<< "wtf:" << word[i] << endl;
                    hav_low = true;
                }
                else {
                    hav_up = true;
                }
            }

            // 如果既存在小写也存在大写字符，则返回false,如果一个true,一个false， 则返回true
            if(hav_low == true && hav_up == true) {
                cout<< "pity" << endl;
                return false;
            }
            else if(hav_low == false && hav_up == true) {
                cout<< "bingo" << endl;
                return true;
            }
            else if(hav_low == true && hav_up == false) return true;
        }
    }
};