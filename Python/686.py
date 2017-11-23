class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        cnt = 1
        cur = A
        if len(cur) >= len(B):
            if cur.find(B) == 0:
                return cnt
        while len(cur) < len(B):
            cur += A
            cnt += 1
        if cur.find(B) != -1:
            return cnt
        cur += A
        cnt += 1
        if cur.find(B) != -1:
            return cnt
        return -1