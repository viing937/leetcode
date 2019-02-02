class Solution:
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        rls = 0
        dic = {}
        for word in words:
            p = self.helper(S, word, dic)
            if p != -1:
                rls += 1
        return rls

    def helper(self, S, word, dic):
        if word in dic:
            return dic[word]
        elif len(word) == 1:
            dic[word] = S.find(word[-1])
        else:
            p = self.helper(S, word[:-1], dic)
            if p == -1:
                dic[word] = -1
            else:
                dic[word] = S.find(word[-1], p+1)
        return dic[word]
