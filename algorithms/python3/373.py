import heapq

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        rls = []
        if len(nums1) <= 0 or len(nums2) <= 0:
            return rls
        pq = [(nums1[i] + nums2[0], i, 0) for i in range(len(nums1))]
        heapq.heapify(pq)
        for i in range(k):
            if len(pq) <= 0:
                break
            s, idx1, idx2 = heapq.heappop(pq)
            rls.append([nums1[idx1], nums2[idx2]])
            if idx2 + 1 < len(nums2):
                heapq.heappush(pq, (nums1[idx1] + nums2[idx2+1], idx1, idx2+1))
        return rls
