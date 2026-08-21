#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Suffix Array:
// Time Complexity:
// build_suffix_array():             O( n log n )
// build_longest_common_prefix():    O( n log n ) + O( n )

// compare():                        Worst: O( m ); AVG: O(m log n)
// search() / find():                O( m log n )
// count occurrences:                O( m log n )

// Space Complexity:
// Suffix Array:     O( n )
// Rank Array:       O( n )
// LCP Array:        O( n )

// Total:
// Memory:           O( n )

class SuffixArray {
private:
    string s;
    int n;

public:
    vector<int> sa;
    vector<int> lcp;

    SuffixArray(const string& str) {
        s = str;
        n = s.size();

        sa = buildSuffixArray();
        lcp = buildLCP();
    }

    vector<int> buildSuffixArray() {
        vector<int> rank(n);
        vector<int> sa(n);

        // Initial ranking by characters
        for (int i = 0; i < n; i++) {
            rank[i] = (unsigned char)s[i];
            sa[i] = i;
        }

        for (int k = 1; k < n; k <<= 1) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];

                int ri = (i + k < n ? rank[i + k] : -1);
                int rj = (j + k < n ? rank[j + k] : -1);

                return ri < rj;
            });

            vector<int> newRank(n);

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int prev = sa[i - 1];
                int curr = sa[i];

                pair<int, int> prevKey = {
                    rank[prev],
                    prev + k < n ? rank[prev + k] : -1
                };

                pair<int, int> currKey = {
                    rank[curr],
                    curr + k < n ? rank[curr + k] : -1
                };

                newRank[curr] =
                    newRank[prev] + (currKey != prevKey);
            }

            rank = newRank;
        }

        return sa;
    }

    vector<int> buildLCP() {
        if (n <= 1)
            return {};

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[sa[i]] = i;
        }

        vector<int> lcp(n - 1);

        int h = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int j = sa[rank[i] - 1];

            while (
                i + h < n &&
                j + h < n &&
                s[i + h] == s[j + h]
            ) {
                h++;
            }

            lcp[rank[i] - 1] = h;

            if (h > 0)
                h--;
        }

        return lcp;
    }


    // How to use:

    // Compare suffix s[i:] with pattern.
    //
    // -1 -> suffix < pattern
    //  0 -> pattern is prefix of suffix
    //  1 -> suffix > pattern
    int compare(int i, const string& pattern) const {
        int m = pattern.size();

        for (int k = 0; k < m; k++) {
            if (i + k >= n)
                return -1;

            if (s[i + k] != pattern[k]) {
                return s[i + k] < pattern[k] ? -1 : 1;
            }
        }

        return 0;
    }

    // Returns [start, end] in suffix array
    // containing all occurrences of pattern.
    //
    // If pattern doesn't occur -> {-1, -1}
    pair<int, int> find(const string& pattern) const {
        // Find first suffix >= pattern
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (compare(sa[mid], pattern) >= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }

        int start = l;

        // Find last suffix <= pattern
        l = 0;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (compare(sa[mid], pattern) <= 0)
                l = mid + 1;
            else
                r = mid - 1;
        }

        int end = r;

        if (
            start >= n ||
            start > end ||
            compare(sa[start], pattern) != 0
        ) {
            return {-1, -1};
        }

        return {start, end};
    }

    bool search(const string& pattern) const {
        auto [start, end] = find(pattern);
        return start != -1;
    }

    int count(const string& pattern) const {
        auto [start, end] = find(pattern);

        if (start == -1)
            return 0;

        return end - start + 1;
    }

};


int main() {
    string s = "banana";

    SuffixArray suffixArray(s);

    cout << "Suffix Array:\n";

    for (int i : suffixArray.sa) {
        cout << i << " -> " << s.substr(i) << '\n';
    }

    cout << "\nLCP:\n";

    for (int x : suffixArray.lcp) {
        cout << x << ' ';
    }

    cout << "\n\n";

    string pattern = "ana";

    cout << "Search: "
         << suffixArray.search(pattern)
         << '\n';

    cout << "Count: "
         << suffixArray.count(pattern)
         << '\n';

    auto [start, end] = suffixArray.find(pattern);

    if (start != -1) {
        cout << "Occurrences at positions:\n";

        for (int i = start; i <= end; i++) {
            cout << suffixArray.sa[i] << ' ';
        }

        cout << '\n';
    }
}
