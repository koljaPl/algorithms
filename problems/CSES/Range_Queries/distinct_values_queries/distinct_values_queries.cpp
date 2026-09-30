#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

class FenwickTree {
private:
    int n;
    vector<ll> bit;

public:
    explicit FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    explicit FenwickTree(const vector<int>& values)
        : n(static_cast<int>(values.size())), bit(n + 1, 0) {

        for (int i = 1; i <= n; i++) {
            bit[i] += values[i - 1];

            int parent = i + (i & -i);

            if (parent <= n) {
                bit[parent] += bit[i];
            }
        }
    }

    void add(int i, ll value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    void subtract(int i, ll value) {
        add(i, -value);
    }

    ll prefix_sum(int i) {
        ll res = 0;

        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }

        return res;
    }

    ll range_sum(int left, int right) {
        return prefix_sum(right) - prefix_sum(left - 1);
    }
};

struct Query {
    int l, r, id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<Query> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }

    sort(qs.begin(), qs.end(), [](const Query& arr, const Query& b) {
        return arr.r < b.r;
    });

    FenwickTree fw(n);

    unordered_map<ll, int> last;
    last.reserve(n * 2);

    vector<int> res(q);
    int pos = 1;
    for (const auto& query : qs) {
        while (pos <= query.r) {
            auto it = last.find(arr[pos]);

            if (it != last.end())
                fw.add(it -> second, -1);

            fw.add(pos, 1);
            last[arr[pos]] = pos;

            pos++;
        }

        res[query.id] = fw.range_sum(query.l, query.r);
    }

    for (int num : res) cout << num << '\n';

    return 0;
}
