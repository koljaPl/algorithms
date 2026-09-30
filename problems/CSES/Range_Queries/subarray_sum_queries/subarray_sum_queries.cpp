#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Node {
    ll sum;
    ll pref;
    ll suff;
    ll best;
};

Node make_node(ll x) {
    ll v = max(0LL, x);
    return {x, v, v, v};
}

struct Merge {
    Node operator()(const Node& a, const Node& b) const {
        Node res;

        res.sum = a.sum + b.sum;

        res.pref = max(a.pref, a.sum + b.pref);
        res.suff = max(b.suff, b.sum + a.suff);
        res.best = max({a.best, b.best, a.suff + b.pref});

        return res;
    }
};

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

    ll max_subarray() const {
        return tree[1].best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Node> arr(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr[i] = make_node(x);
    }

    Node identity = {0, 0, 0, 0};
    IterativeSegmentTree<Node, Merge> st(arr, Merge{}, identity);

    for (int i = 0; i < m; i++) {
        int k;
        ll x;
        cin >> k >> x;

        st.set(k - 1, make_node(x));

        cout << st.max_subarray() << '\n';
    }

    return 0;
}
