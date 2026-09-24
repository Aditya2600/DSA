import math
class TreeAncestor:

    def __init__(self, n: int, parent: list[int]):
        self.rows = n
        self.cols = int(math.log2(n)) + 1
        self.ancestorTable = [
            [-1] * self.cols for _ in range(self.rows)
        ]
        for node in range(self.rows):
            self.ancestorTable[node][0] = parent[node]
        
        for j in range(1, self.cols):
            for node in range(self.rows):
                if self.ancestorTable[node][j-1] != -1:
                    self.ancestorTable[node][j] = self.ancestorTable[self.ancestorTable[node][j-1]][j-1]
                
        

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(self.cols):
            if k & (1 << j):
                node = self.ancestorTable[node][j]
                
                if node == -1:
                    return -1
        return node



# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)