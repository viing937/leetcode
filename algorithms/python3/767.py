import heapq
from collections import Counter
class Solution:
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        if len(S) <= 1:
            return S
        l, c = len(S), [[-item[1], item[0]] for item in Counter(S).items()] + [[1, '#']]
        heapq.heapify(c)
        rls = ''
        for i in range(l):
            t1 = heapq.heappop(c)
            t2 = heapq.heappop(c)
            if rls == '' or t1[1] != rls[-1]:
                rls += t1[1]
                t1[0] += 1
            else:
                if t2[1] == '#':
                    return ''
                rls += t2[1]
                t2[0] += 1
            if t1[0] != 0:
                heapq.heappush(c, t1)
            if t2[0] != 0:
                heapq.heappush(c, t2)
        return rls
