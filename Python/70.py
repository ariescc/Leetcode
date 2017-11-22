class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1, 2]
        for item in range(2, n):
            dp.append(dp[item-2] + dp[item-1])
        return dp[n-1]