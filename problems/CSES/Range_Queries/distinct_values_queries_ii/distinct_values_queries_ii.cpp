#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

template <typename T, typename Merge>
class IterativeSegmentTree {
private:
    int n;
    int size;

    vector<T> tree;

    Merge merge;
    T identity;

public:
    IterativeSegmentTree(
        const vector<T>& arr,
        Merge merge,
        T identity
    )
        : n(arr.size()),
          merge(merge),
          identity(identity)
    {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        tree.assign(2 * size, identity);

        // Leaves
        for (int i = 0; i < n; i++) {
            tree[size + i] = arr[i];
        }

        // Build
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = merge(
                tree[i * 2],
                tree[i * 2 + 1]
            );
        }
    }

    void set(int idx, T value) {
        int pos = size + idx;

        tree[pos] = value;

        pos /= 2;

        while (pos >= 1) {
            tree[pos] = merge(
                tree[pos * 2],
                tree[pos * 2 + 1]
            );

            pos /= 2;
        }
    }

    T query(int left, int right) {
        left += size;

        // [left, right] -> [left, right)
        right += size + 1;

        T res_left = identity;
        T res_right = identity;

        while (left < right) {
            if (left % 2 == 1) {
                res_left = merge(
                    res_left,
                    tree[left]
                );

                left++;
            }

            if (right % 2 == 1) {
                right--;

                res_right = merge(
                    tree[right],
                    res_right
                );
            }

            left /= 2;
            right /= 2;
        }

        return merge(res_left, res_right);
    }
};

struct Q {
    int type;
    int x;
    ll y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> original(n + 1);
    vector<ll> values;
    for (int i = 1; i <= n; i++) {
        cin >> original[i];
        values.pb(original[i]);
    }

    vector<Q> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].type >> qs[i].x >> qs[i].y;

        if (qs[i].type == 1) values.pb(qs[i].y);
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto get_id = [&](ll x) {
        return int(lower_bound(values.begin(), values.end(), x) - values.begin());
    };

    int m = values.size();
    vector<int> a(n + 1);
    vector<set<int>> positions(m);
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(original[i]);
        positions[a[i]].insert(i);
    }

    vector<int> prev(n + 1, 0);
    for (int value = 0; value < m; value++) {
        int last = 0;

        for (int pos : positions[value]) {
            prev[pos] = last;
            last = pos;
        }
    }

    vector<int> arr(n);
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = prev[i];
    }

    auto merge_max = [](int x, int y) {
        return max(x, y);
    };

    IterativeSegmentTree<int, decltype(merge_max)> seg(arr, merge_max, 0);
    for (auto [type, x, y] : qs) {
        if (type == 2) {
            int l = x;
            int r = (int)y;

            int mx = seg.query(l - 1, r - 1);

            if (mx < l) cout << "YES\n";
            else cout << "NO\n";

            continue;
        }

        int k = x;
        int new_value = get_id(y);
        int old_value = a[k];

        if (old_value == new_value) continue;

        auto& old_set = positions[old_value];
        auto it = old_set.find(k);

        int old_prev = 0;
        int old_next = 0;

        if (it != old_set.begin()) {
            auto p = it;
            p--;

            old_prev = *p;
        }

        auto nxt = it;
        nxt++;

        if (nxt != old_set.end())
            old_next = *nxt;

        old_set.erase(it);
        if (old_next != 0) {
            prev[old_next] = old_prev;
            seg.set(old_next - 1, old_prev);
        }

        auto& new_set = positions[new_value];
        auto right = new_set.lower_bound(k);

        int new_prev = 0;
        int new_next = 0;

        if (right != new_set.begin()) {
            auto p = right;
            p--;

            new_prev = *p;
        }

        if (right != new_set.end())
            new_next = *right;

        new_set.insert(k);
        prev[k] = new_prev;
        seg.set(k - 1, new_prev);

        if (new_next != 0) {
            prev[new_next] = k;
            seg.set(new_next - 1, k);
        }

        a[k] = new_value;
    }

    return 0;
}
