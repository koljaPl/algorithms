#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class IterativeSegmentTree {
private:
    int n;
    int size;
    vector<int> tree;

public:
    IterativeSegmentTree(const vector<int>& arr) {
        n = arr.size();

        size = 1;
        while (size < n) {
            size *= 2;
        }

        tree.assign(2 * size, 0);

        for (int i = 0; i < n; i++) {
            tree[size + i] = arr[i];
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] = max(
                tree[2 * i],
                tree[2 * i + 1]
            );
        }
    }

    void set(int idx, int value) {
        int pos = size + idx;
        tree[pos] = value;

        pos /= 2;

        while (pos >= 1) {
            tree[pos] = max(
                tree[2 * pos],
                tree[2 * pos + 1]
            );

            pos /= 2;
        }
    }

    // Запрос максимума на [left, right]
    int query(int left, int right) {
        left += size;
        right += size + 1;

        int resLeft = 0;
        int resRight = 0;

        while (left < right) {
            if (left % 2 == 1) {
                resLeft = max(resLeft, tree[left]);
                left++;
            }

            if (right % 2 == 1) {
                right--;
                resRight = max(tree[right], resRight);
            }

            left /= 2;
            right /= 2;
        }

        return max(resLeft, resRight);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int& x : heights) {
        cin >> x;
    }

    vector<int> left(n, -1);
    vector<int> right(n, n);

    vector<int> st;

    for (int i = 0; i < n; i++) {
        while (
            !st.empty() &&
            heights[st.back()] < heights[i]
        ) {
            st.pop_back();
        }

        if (!st.empty()) {
            left[i] = st.back();
        }

        st.push_back(i);
    }

    st.clear();

    for (int i = n - 1; i >= 0; i--) {
        while (
            !st.empty() &&
            heights[st.back()] < heights[i]
        ) {
            st.pop_back();
        }

        if (!st.empty()) {
            right[i] = st.back();
        }

        st.push_back(i);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(
        order.begin(),
        order.end(),
        [&](int a, int b) {
            return heights[a] < heights[b];
        }
    );

    IterativeSegmentTree segTree(vector<int>(n, 0));

    vector<int> dp(n, 1);

    int res = 1;
    int groupStart = 0;

    while (groupStart < n) {
        int groupEnd = groupStart;
        int currHeight = heights[order[groupStart]];

        while (
            groupEnd < n &&
            heights[order[groupEnd]] == currHeight
        ) {
            groupEnd++;
        }

        for (int k = groupStart; k < groupEnd; k++) {
            int index = order[k];

            int bestNext = segTree.query(
                left[index] + 1,
                right[index] - 1
            );

            dp[index] = bestNext + 1;

            res = max(res, dp[index]);
        }

        for (int k = groupStart; k < groupEnd; k++) {
            int index = order[k];

            segTree.set(
                index,
                dp[index]
            );
        }

        groupStart = groupEnd;
    }

    cout << res << '\n';

    return 0;
}
