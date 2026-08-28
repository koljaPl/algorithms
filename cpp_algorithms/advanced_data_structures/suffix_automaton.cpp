#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Suffix Automaton:
//
// Building:
//      O(n) expected with unordered_map
//
// Check substring of length m:
//      O(m) expected
//
// LCS of strings of lengths n and m:
//      O(n + m)
//
// Number of distinct substrings:
//      O(number of states) = O(n)
//
// Space:
//      O(n)

class SuffixAutomaton {
private:
    struct State {
        unordered_map<char, int> next;
        int link = -1;
        int length = 0;
    };

    vector<State> states;
    int last;

public:
    SuffixAutomaton() {
        states.push_back(State());
        last = 0;
    }

    void extend(char c) {
        int curr = states.size();

        states.push_back(State());

        states[curr].length = states[last].length + 1;

        int p = last;

        // Add transitions by c while they don't exist
        while (p != -1 && !states[p].next.count(c)) {
            states[p].next[c] = curr;
            p = states[p].link;
        }

        if (p == -1) {
            // We reached the root
            states[curr].link = 0;
        } else {
            int q = states[p].next[c];

            // Everything is already correct
            if (states[p].length + 1 == states[q].length) {
                states[curr].link = q;
            } else {
                // Need to create a clone
                int clone = states.size();

                states.push_back(states[q]);

                states[clone].length = states[p].length + 1;

                // Redirect transitions from q to clone
                while (
                    p != -1 &&
                    states[p].next.count(c) &&
                    states[p].next[c] == q
                ) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }

                states[q].link = clone;
                states[curr].link = clone;
            }
        }

        last = curr;
    }

    void build(const string& s) {
        for (char c : s) {
            extend(c);
        }
    }

    bool contains(const string& t) const {
        int v = 0;

        for (char c : t) {
            auto it = states[v].next.find(c);

            if (it == states[v].next.end()) {
                return false;
            }

            v = it->second;
        }

        return true;
    }

    long long count_substrings() const {
        long long result = 0;

        for (int v = 1; v < (int)states.size(); v++) {
            result +=
                states[v].length -
                states[states[v].link].length;
        }

        return result;
    }
};


int main() {
    SuffixAutomaton sa;

    sa.build("ababa");

    cout << boolalpha;

    cout << sa.contains("bab") << '\n';   // true
    cout << sa.contains("abc") << '\n';   // false

    cout << sa.count_substrings() << '\n'; // 9

    return 0;
}
