class TrieNode:
    def __init__(self):
        self.child = {}
        self.isWord = False

    def addWord(self, word):
        node = self
        for ch in word:
            if ch not in node.child:
                node.child[ch] = TrieNode()
            node = node.child[ch]
        node.isWord = True

    def search(self, word):
        child = self.child
        if len(word) == 0:
            return self.isWord
        elif word[0] == '.':
            return any(
                node.search(word[1:]) for node in child.values()
            )
        else:
            return word[0] in child and child[word[0]].search(word[1:])


class WordDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = TrieNode()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str2
        :rtype: void
        """
        self.trie.addWord(word)
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.trie.search(word)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
