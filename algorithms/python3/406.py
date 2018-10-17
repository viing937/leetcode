class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key = lambda x: (x[0], -x[1]))
        rls = [0] * len(people)
        for p in people:
            h, k = p
            i = 0
            while rls[i] != 0 or k:
                if rls[i] == 0:
                    k -= 1
                i += 1
            rls[i] = p
        return rls
