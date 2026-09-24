class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int x, int y) {
        int ulp_x = findUpar(x);
        int ulp_y = findUpar(y);
        if (ulp_x == ulp_y) {
            return;
        }
        if (size[x] > size[y]) {
            parent[ulp_y] = ulp_x;
            size[x] += size[y];
        } else if (size[x] < size[y]) {
            parent[ulp_x] = ulp_y;
            size[y] += size[x];
        } else {
            parent[ulp_x] = ulp_y;
            size[y] += size[x];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        unordered_map<string, int> mp;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else {
                    unionBySize(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mergedAccounts(accounts.size());
        for (auto& it : mp) {
            string mail = it.first;
            int node = findUpar(it.second);
            mergedAccounts[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < accounts.size(); i++) {
            if (mergedAccounts[i].size() == 0)
                continue;
            sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedAccounts[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};