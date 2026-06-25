class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l = 0
        r = n-1
        b = [0]*n
        i = 0
        while i != n:
            v = nums[i]
            if not b[i]:
                if v==0:
                    nums[i],nums[l] = nums[l],nums[i]
                    i = min(i,l)
                    b[l] = 1
                    l += 1
                elif v==2:
                    nums[i],nums[r] = nums[r],nums[i]
                    b[r] = 1
                    i = min(i,r)
                    r -= 1
                else: i += 1
            else: i += 1