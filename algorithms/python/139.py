class TrieNode:
    def __init__(self):
        self.data = {}
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.data.keys():
                node.data[c] = TrieNode()
            node = node.data[c]
        node.isWord = True

    def search(self, word):
        node = self.root
        for c in word:
            if c not in node.data.keys():
                return False
            node = node.data[c]
        return node.isWord

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        trie = Trie()
        for word in wordDict:
            trie.insert(word)

        dp = [False] * (len(s)+1)
        dp[0] = True
        for i in range(len(dp)):
            if not dp[i]:
                continue
            for j in range(i+1, len(dp)):
                if trie.search(s[i:j]):
                    dp[j] = True
        return dp[-1]
