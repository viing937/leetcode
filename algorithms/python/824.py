class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        isVowel = lambda c: c.lower() in ['a', 'e', 'i', 'o', 'u']
        S = S.split(' ')
        for i in range(len(S)):
            if isVowel(S[i][0]):
                S[i] += 'ma'
            else:
                S[i] = S[i][1:] + S[i][0] + 'ma'
            S[i] += 'a' * (i+1)
        return ' '.join(S)
