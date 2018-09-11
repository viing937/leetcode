from bisect import bisect, bisect_left

class RangeModule:
    def __init__(self):
        self.ivs = []

    def addRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        ivs = self.ivs
        low = bisect_left(ivs, left)
        high = bisect(ivs, right)
        if low % 2:
            low -= 1
            left = ivs[low]
        if high % 2:
            high += 1
            right = ivs[high-1]
        self.ivs = ivs[:low] + [left, right] + ivs[high:]

    def queryRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: bool
        """
        ivs = self.ivs
        low = bisect(ivs, left)
        if not low % 2:
            return False
        else:
            return right <= ivs[low]

    def removeRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: void
        """
        ivs = self.ivs
        low = bisect_left(ivs, left)
        high = bisect(ivs, right)
        tmp = []
        if low % 2:
            low -= 1
            tmp += [ivs[low], left]
        if high % 2:
            high += 1
            tmp += [right, ivs[high-1]]
        self.ivs = ivs[:low] + tmp + ivs[high:]


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
