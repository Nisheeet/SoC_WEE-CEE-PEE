class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        l = 0
        ans = 0
        for i in range(len(s)):
            if s[i] in d and d[s[i]] + 1 > l:
                l = d[s[i]]+1
            d[s[i]] = i
            if i-l+1 > ans:
                ans = i-l+1
        return ans