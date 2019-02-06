# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from bisect import bisect
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        data = []
        if not root: return ''
        def dfs(node):
            data.append(node.val)
            if node.left: dfs(node.left)
            if node.right: dfs(node.right)
        dfs(root)
        return ','.join(map(str, data))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        if not data: return None
        def helper(data):
            if not data: return None
            root = TreeNode(data[0])
            bound = bisect(data, data[0], lo=1)
            root.left = helper(data[1:bound])
            root.right = helper(data[bound:])
            return root
        data = list(map(int, data.split(',')))
        return helper(data)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
