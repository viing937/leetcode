class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        arr = str.split(' ')
        if len(pattern) != len(arr):
            return False
        hashmap = {}
        for i in range(len(pattern)):
            if pattern[i] in hashmap.keys() and hashmap[pattern[i]] != arr[i]:
                return False
            hashmap[pattern[i]] = arr[i]
            if hashmap.values().count(arr[i]) > 1:
                return False
        return True
