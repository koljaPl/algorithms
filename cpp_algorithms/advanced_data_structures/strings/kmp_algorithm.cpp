#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> building_pi(string s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

vector<int> kmp_algorithm(string text, string pattern) {
    vector<int> pi = building_pi(pattern);

    int j = 0;
    vector<int> res;

    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (text[i] == pattern[j])
            j++;
            
        if (j == pattern.size()) {
            res.push_back(i - pattern.size() + 1);
            j = pi[j - 1];      
        }
    }

    return res;
}

class KMP {
private:
    string pattern;
    vector<int> pi;

    void build_pi() {
        int m = static_cast<int>(pattern.size());
        pi.assign(m, 0);

        for (int i = 1; i < m; ++i) {
            int j = pi[i - 1];

            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (pattern[i] == pattern[j]) {
                ++j;
            }

            pi[i] = j;
        }
    }

public:
    explicit KMP(string pattern)
        : pattern(std::move(pattern)) {
        build_pi();
    }

    vector<int> search(const string& text) const {
        vector<int> result;

        if (pattern.empty()) {
            return result;
        }

        int n = static_cast<int>(text.size());
        int m = static_cast<int>(pattern.size());
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (text[i] == pattern[j]) {
                ++j;
            }

            if (j == m) {
                result.push_back(i - m + 1);
                j = pi[j - 1];
            }
        }

        return result;
    }

    const vector<int>& prefix_function() const {
        return pi;
    }
};
