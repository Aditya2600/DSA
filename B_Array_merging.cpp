#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        vector<long long> longest_subarray_a(2 * n + 1, 0);
        vector<long long> longest_subarray_b(2 * n + 1, 0);

        long long counter = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                counter++;
            }
            else
            {
                longest_subarray_a[a[i - 1]] = max(longest_subarray_a[a[i - 1]], counter);
                counter = 1;
            }
        }
        longest_subarray_a[a[n - 1]] = max(longest_subarray_a[a[n - 1]], counter);
        counter = 1;
        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                counter++;
            }
            else
            {
                longest_subarray_b[b[i - 1]] = max(longest_subarray_b[b[i - 1]], counter);
                counter = 1;
            }
        }
        longest_subarray_b[b[n - 1]] = max(longest_subarray_b[b[n - 1]], counter);

        long long max_freq = -1;
        for (int i = 1; i <= 2 * n; i++)
        {
            max_freq = max(max_freq, longest_subarray_a[i] + longest_subarray_b[i]);
        }
        cout << max_freq << endl;
    }
    return 0;
}