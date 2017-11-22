class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        elif len(nums) == 3:
            return max(nums[1], nums[0] + nums[2])
        else:
            dp = [nums[0], nums[1], max(nums[1], nums[0] + nums[2])]
            for item in range(3, len(nums)):
                dp.append(max(dp[item-3], dp[item-2]) + nums[item])
            dp.sort()
            return dp[len(nums)-1]