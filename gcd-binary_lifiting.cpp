#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int LOG = 20;

vector<int> neigh[MAXN];
int par[MAXN][LOG], dp[MAXN][LOG], depth[MAXN], val[MAXN];

void dfs(int node, int prev, int dep) {
    par[node][0] = prev;
    depth[node] = dep;
    dp[node][0] = val[node]; // Base GCD case: node itself

    for (int i = 1; i < LOG; i++) {
        if (par[node][i - 1] != -1) { // Ensure ancestor exists
            par[node][i] = par[par[node][i - 1]][i - 1];
            dp[node][i] = gcd(dp[node][i - 1], dp[par[node][i - 1]][i - 1]);
        } else {
            par[node][i] = -1;
        }
    }

    for (auto v : neigh[node]) {
        if (v != prev) {
            dfs(v, node, dep + 1);
        }
    }
}

int pathGCD(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // Ensure u is deeper

    int ans = 0; // Store GCD of the path

    // Bring u and v to the same level
    for (int i = LOG - 1; i >= 0; i--) {
        if ((depth[u] - depth[v]) & (1 << i)) {  // Fixed Precedence Issue
            ans = gcd(ans, dp[u][i]);
            u = par[u][i];
        }
    }

    if (u == v) return gcd(ans, val[u]); // If already same, return GCD

    // Move both u and v upwards until they reach LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = gcd(ans, dp[u][i]); // Fixed incorrect par[v][i]
            ans = gcd(ans, dp[v][i]); // Fixed incorrect par[u][i]
            u = par[u][i];
            v = par[v][i];
        }
    }

    return gcd(ans, val[par[u][0]]);
}