import heapq

class Solution:
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        courses.sort(key=lambda x: x[1])
        s = 0
        pq = []
        for c in courses:
            if s + c[0] <= c[1]:
                heapq.heappush(pq, -c[0])
                s += c[0]
            elif len(pq):
                t = abs(pq[0])
                if t > c[0] and s - t + c[0] <= c[1]:
                    s = s - t + c[0]
                    heapq.heapreplace(pq, -c[0])
        return len(pq)
