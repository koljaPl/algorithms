#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int num) : n(num), bit(num + 1, 0) {}

    void add(int i, int value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    int prefix_sum(int i) {
        int sum_val = 0;

        while (i > 0) {
            sum_val += bit[i];
            i -= i & -i;
        }

        return sum_val;
    }

    int range_sum(int start, int end) {
        return prefix_sum(end) - prefix_sum(start - 1);
    }

    int get_index(int k) {
        int pos = 0;
        int step = 1 << 18;

        while (step) {
            int nxt = pos + step;

            if (nxt <= n && bit[nxt] < k) {
                k -= bit[nxt];
                pos = nxt;
            }

            step >>= 1;
        }

        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Fenwick fw(n);

    for (int i = 1; i < n + 1; i++) {
        fw.add(i, 1);
    }
    
    int curr = 0;
    int alive = n;
    vector<int> res;

    while (alive > 0) {
        curr = (curr + k) % alive;

        int index = fw.get_index(curr + 1);

        res.push_back(index);

        fw.add(index, -1);

        alive -= 1;
    }

    for (int x : res) cout << x << " ";
    
    cout << "\n";

    return 0;
}
