class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        mailMark = S.find('@')
        if mailMark >= 0:
            S = S.lower()
            S = S[0] + '*'*5 + S[mailMark-1:]
        else:
            S = S.replace('+', '').replace('-', '')
            S = S.replace('(', '').replace(')', '')
            S = S.replace(' ', '')
            if len(S) > 10:
                S = '+' + '*'*(len(S)-10) + '-***-***-' + S[-4:]
            else:
                S = '***-***-' + S[-4:]
        return S
