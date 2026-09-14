#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Suffix Tree (Ukkonen)
// Build: O(n)
// Pattern search: O(m)
// Space: O(n)

class SuffixTree {
    struct Node {
        int start;
        shared_ptr<int> end;
        unordered_map<char, int> children;
        int suffixLink = 0;
        int suffixIndex = -1;

        Node(int start, shared_ptr<int> end) : start(start), end(move(end)) {}
    };

    string text;
    vector<Node> tree;

    int root;
    int activeNode;
    int activeEdge = -1;
    int activeLength = 0;
    int remainingSuffixCount = 0;

    shared_ptr<int> leafEnd;
    int n;

    int newNode(int start, shared_ptr<int> end) {
        tree.emplace_back(start, move(end));
        return (int)tree.size() - 1;
    }

    int edgeLength(int node) {
        if (node == root)
            return 0;

        return *tree[node].end - tree[node].start + 1;
    }

    bool walkDown(int node) {
        int len = edgeLength(node);

        if (activeLength >= len) {
            activeEdge += len;
            activeLength -= len;
            activeNode = node;
            return true;
        }

        return false;
    }

    void extend(int pos) {
        *leafEnd = pos;
        remainingSuffixCount++;

        int lastNewNode = -1;

        while (remainingSuffixCount > 0) {
            if (activeLength == 0)
                activeEdge = pos;

            char c = text[activeEdge];

            if (!tree[activeNode].children.count(c)) {
                int leaf = newNode(pos, leafEnd);
                tree[activeNode].children[c] = leaf;

                if (lastNewNode != -1) {
                    tree[lastNewNode].suffixLink = activeNode;
                    lastNewNode = -1;
                }
            } else {
                int next = tree[activeNode].children[c];

                if (walkDown(next))
                    continue;

                if (text[tree[next].start + activeLength] == text[pos]) {
                    if (lastNewNode != -1 && activeNode != root) {
                        tree[lastNewNode].suffixLink = activeNode;
                        lastNewNode = -1;
                    }

                    activeLength++;
                    break;
                }

                auto splitEnd =
                    make_shared<int>(tree[next].start + activeLength - 1);

                int split = newNode(tree[next].start, splitEnd);

                tree[activeNode].children[c] = split;

                int leaf = newNode(pos, leafEnd);
                tree[split].children[text[pos]] = leaf;

                tree[next].start += activeLength;
                tree[split].children[text[tree[next].start]] = next;

                if (lastNewNode != -1)
                    tree[lastNewNode].suffixLink = split;

                lastNewNode = split;
            }

            remainingSuffixCount--;

            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = pos - remainingSuffixCount + 1;
            } else if (activeNode != root) {
                activeNode = tree[activeNode].suffixLink;
            }
        }
    }

    void setSuffixIndex(int node, int height) {
        if (tree[node].children.empty()) {
            tree[node].suffixIndex = n - height;
            return;
        }

        for (auto [c, child] : tree[node].children)
            setSuffixIndex(child, height + edgeLength(child));
    }

public:
    SuffixTree(const string& s) : text(s), n(s.size()) {
        leafEnd = make_shared<int>(-1);

        root = newNode(-1, make_shared<int>(-1));
        tree[root].suffixLink = root;

        activeNode = root;

        for (int i = 0; i < n; i++)
            extend(i);

        setSuffixIndex(root, 0);
    }

    bool contains(const string& pattern) {
        int node = root;
        int p = 0;

        while (p < (int)pattern.size()) {
            char c = pattern[p];

            if (!tree[node].children.count(c))
                return false;

            int child = tree[node].children[c];

            for (int i = tree[child].start;
                 i <= *tree[child].end && p < (int)pattern.size();
                 i++, p++) {

                if (text[i] != pattern[p])
                    return false;
            }

            node = child;
        }

        return true;
    }
};
