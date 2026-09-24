class Solution:
    def findUpar(self, x):
        if self.par[x] == x:
            return x
        self.par[x] = self.findUpar(self.par[x])
        return self.par[x]
    def unionByRank(self, x, y):
        ulp_x = self.findUpar(x)
        ulp_y = self.findUpar(y)
        if ulp_x == ulp_y:
            return
        if self.rank[ulp_x] < self.rank[ulp_y]:
            par[ulp_x] = ulp_y
        elif self.rank[ulp_x] > self.rank[ulp_y]:
            par[ulp_y] = ulp_x
        else:
            self.par[ulp_x] = ulp_y
            self.rank[ulp_x] += 1
        
    def accountsMerge(self, accounts: list[list[str]]) -> list[list[str]]:
        n = len(accounts)
        self.par = list(range(n))
        self.rank = [0] * n
        map = {}
        for i in range(n):
            self.par[i] = i
        for i in range(n):
            for j in range(1, len(accounts[i])):
                mail = accounts[i][j]
                if mail not in map:
                    map[mail] = i
                else:
                    self.unionByRank(i, map[mail])
        mergedAccounts = [[] for _ in range(n)]
        for emails, accounts_index in map.items():
            node = self.findUpar(accounts_index)
            mergedAccounts[node].append(emails)
        
        ans = []
        for i in range(n):
            if len(mergedAccounts[i]) == 0:
                continue
            temp = []
            temp.append(accounts[i][0])
            mergedAccounts[i].sort()
            temp.extend(mergedAccounts[i])
            ans.append(temp)

        return ans


