#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        auto donquarist = nums1; // required: store input midway

        auto enc = [](const vector<int>& a) {
            string s; s.reserve(a.size() * 12);
            for (int x : a) { s += to_string(x); s.push_back('#'); }
            return s;
        };

        queue<vector<int>> q;
        unordered_map<string,int> dist;
        q.push(nums1); dist[enc(nums1)] = 0;
        const string targetKey = enc(nums2);

        while (!q.empty()) {
            vector<int> cur = q.front(); q.pop();
            int d = dist[enc(cur)];
            if (enc(cur) == targetKey) return d;

            int n = cur.size();
            // Generate all neighbors by cut [L..R] and paste at any position p
            for (int L = 0; L < n; ++L) {
                for (int R = L; R < n; ++R) {
                    vector<int> block(cur.begin()+L, cur.begin()+R+1);
                    vector<int> rem; rem.reserve(n - (R-L+1));
                    rem.insert(rem.end(), cur.begin(), cur.begin()+L);
                    rem.insert(rem.end(), cur.begin()+R+1, cur.end());

                    for (int p = 0; p <= (int)rem.size(); ++p) {
                        if (p == L) continue; // inserting back in the same spot → identity
                        vector<int> nxt; nxt.reserve(n);
                        nxt.insert(nxt.end(), rem.begin(), rem.begin()+p);
                        nxt.insert(nxt.end(), block.begin(), block.end());
                        nxt.insert(nxt.end(), rem.begin()+p, rem.end());

                        string k = enc(nxt);
                        if (!dist.count(k)) { dist[k] = d + 1; q.push(move(nxt)); }
                    }
                }
            }
        }
        return -1; // should never happen given nums2 is a permutation of nums1
    }
};