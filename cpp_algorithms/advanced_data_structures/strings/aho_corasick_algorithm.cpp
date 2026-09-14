#include <bits/stdc++.h>
using namespace std;

// Aho-Corasick Algorithm:

// Time Complexity:
// build():  O(Σ|s| * alphabet length) (if easier, then the sum of the lengths)
//           - O(Σ|s|) for constant alphabet
// add():    O(length of word)
// search(): O(|text| + matches)
//
// Space Complexity:
// Memory:   O(m * |Σ|), where m is the sum of the lengths
//                       of all keywords in the dictionary,
// or we also can say O(total number of trie nodes * alphabet)

class AhoCorasick {
public:
    static const int ALPHABET = 26;
    static const char FIRST = 'a';

    struct Node {
        array<int, ALPHABET> next;
        int link;
        vector<int> out;

        Node() {
            next.fill(-1);
            link = 0;
        }
    };

    vector<Node> nodes;

    AhoCorasick() {
        nodes.emplace_back();
    }

    void build() {
        queue<int> q;

        // Инициализация детей корня
        for (int c = 0; c < ALPHABET; ++c) {
            int u = nodes[0].next[c];

            if (u != -1) {
                nodes[u].link = 0;
                q.push(u);
            } else {
                nodes[0].next[c] = 0;
            }
        }

        // BFS
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int c = 0; c < ALPHABET; ++c) {
                int u = nodes[v].next[c];

                if (u != -1) {
                    // suffix link
                    nodes[u].link = nodes[nodes[v].link].next[c];

                    // наследуем output
                    for (int word_id : nodes[nodes[u].link].out) {
                        nodes[u].out.push_back(word_id);
                    }

                    q.push(u);
                } else {
                    // automaton transition
                    nodes[v].next[c] = nodes[nodes[v].link].next[c];
                }
            }
        }
    }

    void add_word(const string& word, int word_id) {
        int v = 0;

        for (char ch : word) {
            int c = ch - FIRST;

            if (nodes[v].next[c] == -1) {
                nodes[v].next[c] = nodes.size();
                nodes.emplace_back();
            }

            v = nodes[v].next[c];
        }

        nodes[v].out.push_back(word_id);
    }

    vector<pair<int, int>> search(const string& text) {
        int v = 0;
        vector<pair<int, int>> matches;

        for (int i = 0; i < (int)text.size(); ++i) {
            int c = text[i] - FIRST;

            v = nodes[v].next[c];

            for (int word_id : nodes[v].out) {
                matches.emplace_back(i, word_id);
            }
        }

        return matches;
    }
};

// Intuition / Idea:

// "Ахо-Корасик — это trie, который умеет умно откатываться как KMP
// и поэтому ищет много строк одновременно за линейное время"

// "Этот алгоритм решает задачу:
// «Дан набор строк (паттернов).
// Нужно быстро искать все их вхождения в тексте.»"

// How to use it?

int main() {
    vector<string> patterns = {
        "he",
        "she",
        "hers",
        "his"
    };

    AhoCorasick ac;

    for (int i = 0; i < (int)patterns.size(); ++i) {
        ac.add_word(patterns[i], i);
    }

    ac.build();

    string text = "ahishers";

    auto matches = ac.search(text);

    for (auto [pos, pattern_id] : matches) {
        string word = patterns[pattern_id];

        int end_pos = pos;
        int start_pos = pos - word.size() + 1;

        cout << "Found '" << word
             << "' at [" << start_pos
             << ", " << end_pos << "]\n";
    }
}

// Where to use:
//
// 1. Найти все паттерны
//
// 2. Forbidden strings:
//      Например:
//          "найти количество строк длины n,
//           которые НЕ содержат плохих подстрок"
//
//      - Тогда:
//          строим AC automaton
//          DP по состояниям автомата
//
// 3. Shortest string containing all patterns
//
// 4. Lexicographically smallest valid string
//
// 5. DP по автомату
//
// 6. Count occurrences of each pattern
//
// Также в олимпиадных задачах:
//
// Когда есть:
//
// много шаблонов
// один большой текст
// нужно искать все одновременно
//
// Типичные формулировки:
//
// найти количество вхождений
// проверить существование
// найти минимальную строку
// DP по автомату
// BFS по автомату
// forbidden strings
// mask DP + AC automaton