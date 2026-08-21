#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree {
private:
    int n;
    vector<int> bit;

public:
    explicit FenwickTree(int size)
        : n(size), bit(size + 1, 0) {}

    void add(int index, int value) {
        while (index <= n) {
            bit[index] += value;
            index += index & -index;
        }
    }

    void subtract(int index, int value) {
        add(index, -value);
    }

    int prefixSum(int index) const {
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }

    int rangeSum(int left, int right) const {
        return prefixSum(right) - prefixSum(left - 1);
    }

    int kth(int k) const {
        int index = 0;

        int step = 1;
        while ((step << 1) <= n) {
            step <<= 1;
        }

        while (step > 0) {
            int nextIndex = index + step;

            if (nextIndex <= n && bit[nextIndex] < k) {
                index = nextIndex;
                k -= bit[nextIndex];
            }

            step >>= 1;
        }

        return index + 1;
    }
};

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies;
    movies.reserve(n);

    vector<int> times;
    times.reserve(n + 1);
    times.push_back(0);

    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;

        movies.emplace_back(start, finish);
        times.push_back(finish);
    }

    sort(movies.begin(), movies.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;
         });

    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());

    FenwickTree fenwick(static_cast<int>(times.size()));

    int zeroIndex =
        static_cast<int>(upper_bound(times.begin(), times.end(), 0)
                         - times.begin());

    fenwick.add(zeroIndex, k);

    int result = 0;

    for (auto [start, finish] : movies) {
        int position =
            static_cast<int>(upper_bound(times.begin(), times.end(), start)
                             - times.begin());

        int availableCount = fenwick.prefixSum(position);

        if (availableCount == 0) {
            continue;
        }

        int memberIndex = fenwick.kth(availableCount);

        fenwick.add(memberIndex, -1);

        int finishIndex =
            static_cast<int>(lower_bound(times.begin(), times.end(), finish)
                             - times.begin()) + 1;

        fenwick.add(finishIndex, 1);

        result++;
    }

    cout << result << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;

    sort(movies.begin(), movies.end());

    multiset<int> ends;
    for (int i = 0; i < k; i++)
        ends.insert(0);

    int res = 0;
    for (auto [finish, start] : movies) {
        auto it = ends.upper_bound(start);

        if (it == ends.begin())
            continue;

        it--;
        ends.erase(it);
        ends.insert(finish);
        res++;
    }

    cout << res << '\n';

    return 0;
}
