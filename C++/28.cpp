// 获取模式串的 next数组
// next数组存储的是子串的最长重合前后缀子串长度 : a 最长重合前后缀子串长度为0，next[0] = -1
void get_next(char *str, int *next, int len)
{
    next[0] = -1;
    int k = -1; // 最长重合前后缀子串长度, 不存在重合前后缀子串的话，next数组赋值为-1

    // 每次循环均求出长度为 q+1 的子串的最长前后缀子串长度,即next[q]的值
    for(int q = 1; q < len; q++) {

        while(k > -1 && str[k+1] != str[q]) {
            // 试探将重合子串长度增加1观察能否与子串的最后一位字符匹配，匹配的话在当前最长重合子缀长度下增加1
            // 不相同的情况下则从上一个长度所存的重合子缀长度进行回溯试探
            k = next[k];
        }

        // 如果试探成功，则最长重合子串长度增加1
        if(str[k+1] == str[q]) {
            k = k + 1;
        }
        next[q] = k;
    }
}


// kmp 算法
// params str 主串
// params slen 主串长度
// params ptr 模式串
// params plen 模式串长度
int kmp(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    int k = -1; // 匹配的模式串长度

    get_next(ptr, next, plen);

    for(int i = 0; i < slen; i++) {
        while(k > -1 && ptr[k+1] != str[i]) {
            // 模式串试探性增加1位，没有匹配成功则回溯继续进行试探
            k = next[k];
        }

        // 模式串增加一位试探成功，模式串匹配成功的子串长度增加1
        if(ptr[k+1] == str[i]) {
            k = k + 1;
        }

        // 模式串匹配完成，即此时当前所匹配的最长模式串子串长度等于模式串长度
        if(k == plen - 1) {
            // 此时i处在主串匹配成功模式串的最后一位
            // 返回匹配成功的开始位置
            return i - plen + 1;
        }
    }
}
