class Solution {
public:
    vector<int> evenSubTree1, oddSubTree1, totalEven1, totalOdd1, evenSubTree2,
        oddSubTree2, totalEven2, totalOdd2;
    vector<vector<int>> gr1;
    vector<vector<int>> gr2;
    void dfs1Tree1(int node, int parent) {
        evenSubTree1[node] = 1;
        oddSubTree1[node] = 0;
        for (int ne : gr1[node]) {
            if (ne != parent) {
                dfs1Tree1(ne, node);
                evenSubTree1[node] += oddSubTree1[ne];
                oddSubTree1[node] += evenSubTree1[ne];
            }
        }
    }

    void dfs2Tree1(int node, int parent, int evenAbove, int oddAbove) {
        totalEven1[node] = evenSubTree1[node] + evenAbove;
        totalOdd1[node] = oddSubTree1[node] + oddAbove;

        for (int ne : gr1[node]) {
            if (ne != parent) {
                int evenUp = totalOdd1[node] - evenSubTree1[ne];
                int oddUp = totalEven1[node] - oddSubTree1[ne];
                dfs2Tree1(ne, node, evenUp, oddUp);
            }
        }
    }

    void dfs1Tree2(int node, int parent) {
        evenSubTree2[node] = 1;
        oddSubTree2[node] = 0;
        for (int ne : gr2[node]) {
            if (ne != parent) {
                dfs1Tree2(ne, node);
                evenSubTree2[node] += oddSubTree2[ne];
                oddSubTree2[node] += evenSubTree2[ne];
            }
        }
    }

    void dfs2Tree2(int node, int parent, int evenAbove, int oddAbove) {
        totalEven2[node] = evenSubTree2[node] + evenAbove;
        totalOdd2[node] = oddSubTree2[node] + oddAbove;

        for (int ne : gr2[node]) {
            if (ne != parent) {
                int evenUp = totalOdd2[node] - evenSubTree2[ne];
                int oddUp = totalEven2[node] - oddSubTree2[ne];
                dfs2Tree2(ne, node, evenUp, oddUp);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        gr1.resize(n);
        for (vector<int> edge : edges1) {
            int node = edge[0], ne = edge[1];
            gr1[node].push_back(ne);
            gr1[ne].push_back(node);
        }

        gr2.resize(m);
        for (vector<int> edge : edges2) {
            int node = edge[0], ne = edge[1];
            gr2[node].push_back(ne);
            gr2[ne].push_back(node);
        }

        evenSubTree1.resize(n);
        oddSubTree1.resize(n);
        totalEven1.resize(n);
        totalOdd1.resize(n);
        evenSubTree2.resize(m);
        oddSubTree2.resize(m);
        totalEven2.resize(m);
        totalOdd2.resize(m);
        dfs1Tree1(0, -1);
        dfs2Tree1(0, -1, 0, 0);
        dfs1Tree2(0, -1);
        dfs2Tree2(0, -1, 0, 0);

        int goldenNode = 0;
        int maxTotalOdd = totalOdd2[0];
        for (int i = 1; i < m; i++) {
            if (totalOdd2[i] > maxTotalOdd) {
                maxTotalOdd = totalOdd2[i];
                goldenNode = i;
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = totalEven1[i] + maxTotalOdd;
        }
        return ans;
    }
};