class Solution {
public:
    using ll = long long;

    ll C(ll n) {
        if (n < 0)
            return 0;
        return n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        ll total = C(n + 2);

        ll overA = C(n - limit + 1);
        ll overB = overA; // same
        ll overC = overA;

        ll overAB = C(n - 2 * limit);
        ll overAC = overAB;
        ll overBC = overAB;

        ll overABC = C(n - 3 * limit - 1);

        return total - (overA + overB + overC) + (overAB + overAC + overBC) -
               overABC;
    }
};