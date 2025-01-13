#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {

    freopen("Edata.in","r",stdin);
    freopen("std.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<i64> pre(N + 1);
    for (int i = 0; i < N; i++) {
        pre[i + 1] = pre[i] + A[i];
    }
    
    i64 ans = 0;
    for (int i = 0; i <= N; i++) {
        pre[i] %= M;
        ans += pre[i] * i;
        ans -= pre[i] * (N - i);
    }
    
    Fenwick<int> fen(N + 1);
    
    std::vector<int> p(N + 1);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            if (pre[i] != pre[j]) {
                return pre[i] > pre[j];
            }
            return i > j;
        });
    
    for (auto i : p) {
        ans += 1LL * fen.sum(i) * M;
        fen.add(i, 1);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}