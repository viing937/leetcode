class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        m, n = len(nums), len(nums[0])
        if m*n != r*c: return nums

        rls = [[0]*c for _ in range(r)]
        for i in range(m*n):
            rls[i//c][i%c] = nums[i//n][i%n]
        return rls
