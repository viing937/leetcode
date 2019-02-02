class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = S.replace('-', '').upper()
        arr = []
        if len(S) % K:
            arr.append(S[:len(S)%K])
            S = S[len(S)%K:]
        arr += [S[i:i+K] for i in range(0, len(S), K)]
        return '-'.join(arr)
