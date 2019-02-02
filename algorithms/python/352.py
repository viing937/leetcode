# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class SummaryRanges:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intervals = set()
        self.isExist = set()
        self.leftBound, self.rightBound = {}, {}

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        if val in self.isExist: return
        self.isExist.add(val)
        left, right = val, val
        if val+1 in self.leftBound:
            right = self.leftBound[val+1].end
            self.intervals.remove(self.leftBound[val+1])
            del self.leftBound[val+1]
            del self.rightBound[right]
        if val-1 in self.rightBound:
            left = self.rightBound[val-1].start
            self.intervals.remove(self.rightBound[val-1])
            del self.leftBound[left]
            del self.rightBound[val-1]
        ivl = Interval(left, right)
        self.intervals.add(ivl)
        self.leftBound[left] = ivl
        self.rightBound[right] = ivl

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        return sorted(self.intervals, key=lambda x:x.start)


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
