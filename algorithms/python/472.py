class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        words = set(words)
        rls = list(filter(lambda x: self.helper(x, words), words))
        return rls

    def helper(self, w, words):
        for i in range(1, len(w)):
            if w[:i] in words and w[i:] in words:
                return True
            elif w[:i] in words:
                if self.helper(w[i:], words):
                    return True
        return False
