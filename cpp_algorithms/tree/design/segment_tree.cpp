#include <bits/stdc++.h>
using namespace std;

// Segment Tree:
//
// Time Complexity:
// Query:    O(log n)
// Update:   O(log n)
// Build:  	O(n)
//
// Space Complexity:
// Memory:   O(4 * n)

template <typename T, typename Merge>
class SegmentTree {
private:
    int n;

    vector<T> arr;
    vector<T> tree;

    Merge merge;
    T identity;

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    T helper_query(
        int node,
        int left,
        int right,
        int start,
        int end
    ) {
        if (end < left || right < start) {
            return identity;
        }

        if (start <= left && right <= end) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;

        T left_side = helper_query(
            node * 2,
            left,
            mid,
            start,
            end
        );

        T right_side = helper_query(
            node * 2 + 1,
            mid + 1,
            right,
            start,
            end
        );

        return merge(left_side, right_side);
    }

    void helper_update(
        int node,
        int left,
        int right,
        int index,
        T value
    ) {
        if (left == right) {
            tree[node] = value;
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {
            helper_update(
                node * 2,
                left,
                mid,
                index,
                value
            );
        } else {
            helper_update(
                node * 2 + 1,
                mid + 1,
                right,
                index,
                value
            );
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    SegmentTree(
        const vector<T>& arr,
        Merge merge,
        T identity
    )
        : n(arr.size()),
          arr(arr),
          tree(4 * arr.size(), identity),
          merge(merge),
          identity(identity)
    {
        if (n > 0) {
            build(1, 0, n - 1);
        }
    }

    T query(int start, int end) {
        return helper_query(
            1,
            0,
            n - 1,
            start,
            end
        );
    }

    void update(int index, T value) {
        helper_update(
            1,
            0,
            n - 1,
            index,
            value
        );
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
};

// How to use:
//
// ==================== SUM TREE ====================
//
// auto merge = [](long long a, long long b) {
//     return a + b;
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
// st.query(l, r);          // sum on [l, r]
// st.update(index, value); // arr[index] = value
//
//
// ==================== MIN TREE ====================
//
// auto merge = [](long long a, long long b) {
//     return min(a, b);
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     LLONG_MAX
// );
//
// st.query(l, r);          // minimum on [l, r]
// st.update(index, value); // arr[index] = value
//
//
// ==================== MAX TREE ====================
//
// auto merge = [](long long a, long long b) {
//     return max(a, b);
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     LLONG_MIN
// );
//
// st.query(l, r);          // maximum on [l, r]
// st.update(index, value); // arr[index] = value
//
//
// ==================== XOR TREE ====================
//
// auto merge = [](long long a, long long b) {
//     return a ^ b;
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
// st.query(l, r);          // XOR on [l, r]
// st.update(index, value); // arr[index] = value
//
//
// ==================== GCD TREE ====================
//
// auto merge = [](long long a, long long b) {
//     return gcd(a, b);
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
// st.query(l, r);          // GCD on [l, r]
// st.update(index, value); // arr[index] = value
//
//
// ==================== ITERATIVE SEGMENT TREE ====================
//
// SUM:
//
// auto merge = [](long long a, long long b) {
//     return a + b;
// };
//
// IterativeSegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
// st.query(l, r);     // query on [l, r]
// st.set(index, value); // arr[index] = value
//
//
// MIN:
//
// auto merge = [](long long a, long long b) {
//     return min(a, b);
// };
//
// IterativeSegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     LLONG_MAX
// );
//
//
// MAX:
//
// auto merge = [](long long a, long long b) {
//     return max(a, b);
// };
//
// IterativeSegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     LLONG_MIN
// );
//
//
// XOR:
//
// auto merge = [](long long a, long long b) {
//     return a ^ b;
// };
//
// IterativeSegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
//
// GCD:
//
// auto merge = [](long long a, long long b) {
//     return gcd(a, b);
// };
//
// IterativeSegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
//
// int n, q;
// cin >> n >> q;
//
// vector<long long> arr(n);
//
// for (long long& x : arr) {
//     cin >> x;
// }
//
// auto merge = [](long long a, long long b) {
//     return a + b;
// };
//
// SegmentTree<long long, decltype(merge)> st(
//     arr,
//     merge,
//     0LL
// );
//
// while (q--) {
//     string type;
//     cin >> type;
//
//     if (type == "query") {
//         int l, r;
//         cin >> l >> r;
//
//         cout << st.query(l, r) << '\n';
//     }
//     else {
//         int index;
//         long long value;
//
//         cin >> index >> value;
//
//         st.update(index, value);
//     }
// }
