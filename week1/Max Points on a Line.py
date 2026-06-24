class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        ans = 1
        d = {}
        n = len(points)
        for i in range(n-1):
            x1,y1=points[i]
            for j in range(i+1,n):
                x2,y2=points[j]

                if x1==x2: slope = None
                else: slope = float(y2-y1)/(x2-x1)

                if slope not in d: d[slope]=2
                else: d[slope] += 1
            here = max(d.values())
            ans = max(ans,here)
            d = {}
        return ans