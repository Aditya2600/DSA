class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        DisjointSet ds(n);

        // Precompute frequency arrays for each property list
        vector<bitset<101>> freq(n); // Since elements are in range [1, 100]
        for (int i = 0; i < n; i++) {
            for (int num : properties[i]) {
                freq[i][num] = 1;
            }
        }

        // Compare properties and create edges based on common elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int common = (freq[i] & freq[j]).count(); // Count common elements
                if (common >= k) {
                    ds.unionBySize(i, j);
                }
            }
        }

        // Count unique components
        unordered_set<int> uniqueComponents;
        for (int i = 0; i < n; i++) {
            uniqueComponents.insert(ds.findUPar(i));
        }

        return uniqueComponents.size();
    }
};