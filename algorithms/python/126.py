class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        wordList = set(wordList)
        if endWord not in wordList: return []

        layer = {}
        layer[beginWord] = [[beginWord]]
        while len(layer):
            newLayer = {}
            for last in layer:
                if last == endWord:
                    return layer[last]
                for i in range(len(last)):
                    for ch in 'abcdefghijklmnopqrstuvwxyz':
                        word = last[:i] + ch + last[i+1:]
                        if word not in wordList:
                            continue
                        if word not in newLayer:
                            newLayer[word] = []
                        newLayer[word] += [cur+[word] for cur in layer[last]]
            wordList -= set(newLayer.keys())
            layer = newLayer
        return []
