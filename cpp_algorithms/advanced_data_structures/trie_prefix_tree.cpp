#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Trie (Prefix Tree) Data Structure:
//
// Time Complexity:
//
// insert()          O(L)
// search()          O(L)
// starts_with()     O(L)
// delete()          O(L)
// count_prefix()    O(L)
//
// Where L is length of word (or prefix)
//
// Access to nodes letters:
//
// TrieNode:                     amortized O(1)
// TrieNodeMemoryOptimized:      Real O(1) (isn't it cool, huh?)
//
// Space Complexity:
//
// Memory:
//
// Worst Case:
//
// O( N * L * R )
//
// Where:
//
// N is the number of keys/strings
// L is the average or maximum length of a string
// R is the alphabet size
//
// but, it's more true:
//
// Space: O(total characters inserted)
// Worst-case: O( N * L )
//
// or we also can say:
//
// O( total number of nodes * R )
//
// or even
//
// O( sum of lengths of all inserted strings * R )

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;

    bool is_word;
    int prefix_count;

    TrieNode() {
        is_word = false;
        prefix_count = 0;
    }
};

// Slightly better in terms of memory
//
// But you’ll have to add everything as numbers ( ord() )
//
// and only a-z lowercase letters
//
// and also requires mapping: char -> index (c - 'a')

class TrieNodeMemoryOptimized {
public:
    array<TrieNodeMemoryOptimized*, 26> children;

    bool is_word;
    int prefix_count;

    TrieNodeMemoryOptimized() {
        children.fill(nullptr);

        is_word = false;
        prefix_count = 0;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // O(L)
    void insert(const string& word) {
        TrieNode* node = root;

        for (char c : word) {

            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];

            node->prefix_count++;
        }

        node->is_word = true;
    }

    // O(L)
    bool search(const string& word) {
        TrieNode* node = root;

        for (char c : word) {

            if (!node->children.count(c)) {
                return false;
            }

            node = node->children[c];
        }

        return node->is_word;
    }

    // O(L)
    bool starts_with(const string& prefix) {
        TrieNode* node = root;

        for (char c : prefix) {

            if (!node->children.count(c)) {
                return false;
            }

            node = node->children[c];
        }

        return true;
    }

    // O(L)
    // This does NOT remove nodes, only unmarks word existence
    bool remove_word_flag(const string& word) {
        // We also can name it delete, but it's not very true

        TrieNode* node = root;

        for (char c : word) {

            if (!node->children.count(c)) {
                return false;

                // return "No Word Found"
            }

            node = node->children[c];
        }

        node->is_word = false;

        return true;
        // return "Successfully Deleted"
    }

    // O(L)
    int count_prefix(const string& prefix) {
        // prefix_count excludes or includes word ending at node depending on definition

        TrieNode* node = root;

        for (char c : prefix) {

            if (!node->children.count(c)) {
                return 0;
            }

            node = node->children[c];
        }

        return node->prefix_count;
    }
};

// Intuition / Idea:
//
// Trie = дерево префиксов, где строки "склеиваются" по общим началам, и поиск становится очень быстрым по длине слова.
//
// Trie — это дерево, где:
//
// каждая вершина = символ
//
// путь от корня до узла = префикс строки
//
// слово заканчивается в узле, где стоит “флаг окончания”
//
// Usage:
//
// Trie trie;
//
// trie.insert("cat");
// trie.insert("car");
// trie.insert("care");
//
// cout << trie.search("cat") << '\n';       // True
// cout << trie.search("ca") << '\n';        // False
//
// cout << trie.starts_with("ca") << '\n';   // True
// cout << trie.starts_with("dog") << '\n';  // False
//
// Where to use in problems:
//
// 1. Word Dictionary
// 2. Maximum XOR (Binary Trie)
// 3. Prefix counting
//          - сколько слов начинается с prefix
// 4. Unique Prefix
//          - Найти минимальный уникальный префикс каждого слова.
// 5. Lexicographical traversal
// 6. Aho-Corasick