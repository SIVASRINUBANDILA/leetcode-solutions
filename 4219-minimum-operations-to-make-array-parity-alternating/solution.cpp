#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int> merunavilo = nums;
        int n = merunavilo.size();
        if (n <= 1) return {0, 0};

        auto solve = [&](int start_parity) -> pair<int, int> {
            int ops = 0;
            long long f_min = LLONG_MAX, f_max = LLONG_MIN;
            vector<long long> flex;

            for (int i = 0; i < n; ++i) {
                int expected = (i % 2 == 0) ? start_parity : 1 - start_parity;
                if (abs(merunavilo[i] % 2) == expected) {
                    f_min = min(f_min, (long long)merunavilo[i]);
                    f_max = max(f_max, (long long)merunavilo[i]);
                } else {
                    ops++;
                    flex.push_back(merunavilo[i]);
                }
            }

            auto check = [&](long long K) {
                if (K == 0) {
                    long long target;
                    if (f_min != LLONG_MAX) {
                        if (f_min != f_max) return false;
                        target = f_min;
                        for (long long v : flex) {
                            if (v - 1 != target && v + 1 != target) return false;
                        }
                        return true;
                    } else {
                        if (flex.empty()) return true;
                        target = flex[0] - 1;
                        bool ok = true;
                        for (long long v : flex) {
                            if (v - 1 != target && v + 1 != target) { ok = false; break; }
                        }
                        if (ok) return true;
                        
                        target = flex[0] + 1;
                        ok = true;
                        for (long long v : flex) {
                            if (v - 1 != target && v + 1 != target) { ok = false; break; }
                        }
                        return ok;
                    }
                }

                long long L_min = -3000000000LL;
                long long L_max = 3000000000LL;

                if (f_min != LLONG_MAX) {
                    L_min = max(L_min, f_max - K);
                    L_max = min(L_max, f_min);
                }

                for (long long v : flex) {
                    L_min = max(L_min, v - 1 - K);
                    L_max = min(L_max, v + 1);
                }

                return L_min <= L_max;
            };

            long long l = 0, r = 4000000000LL, ans_range = r;
            while (l <= r) {
                long long mid = l + (r - l) / 2;
                if (check(mid)) {
                    ans_range = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return {ops, (int)ans_range};
        };

        pair<int, int> res0 = solve(0);
        pair<int, int> res1 = solve(1);

        if (res0.first < res1.first) return {res0.first, res0.second};
        if (res1.first < res0.first) return {res1.first, res1.second};
        return {res0.first, min(res0.second, res1.second)};
    }
};
