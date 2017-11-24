class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        tem = s[::-1]
        cnt = -1
        cur = list()
        st = list()
        if tem == s:
            return True
        else:
            for i in range(len(s)):
                if s[i] != tem[i]:
                    cnt = i
                    break
            for j in range(len(tem)):
                if j != cnt:
                    cur.append(tem[j])
            tem_cmp = cur[::-1]
            for k in range(len(s)):
                if k != cnt:
                   st.append(s[k])
            st_cmp = st[::-1] 
            if tem_cmp == cur or st_cmp == st:
                return True
            else:
                return False
# a b c d c b c a
# a c b c d c b a