#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back


template <typename K, typename V>
class HashMap {
private:
    int size;

    vector<list<pair<K, V>>> table;

    int _hash(const K& key) const {
        return hash<K>{}(key) % size;
    }

public:
    HashMap(int size = 1024) {
        this->size = size;
        table.resize(size);
    }

    void put(const K& key, const V& value) {
        int index = _hash(key);

        auto& bucket = table[index];

        for (auto& [k, v] : bucket) {
            if (k == key) {
                v = value;
                return;
            }
        }

        bucket.push_back({key, value});
    }

    V get(const K& key) const {
        int index = _hash(key);

        const auto& bucket = table[index];

        for (const auto& [k, v] : bucket) {
            if (k == key) {
                return v;
            }
        }

        throw out_of_range("Key not found");
    }

    void remove(const K& key) {
        int index = _hash(key);

        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }

        throw out_of_range("Key not found");
    }

    bool contains(const K& key) const {
        int index = _hash(key);

        const auto& bucket = table[index];

        for (const auto& [k, v] : bucket) {
            if (k == key) {
                return true;
            }
        }

        return false;
    }
};

// How to use it:
int main() {
    HashMap<string, int> mp;

    mp.put("apple", 10);
    mp.put("banana", 20);

    cout << mp.get("apple") << '\n';     // 10

    mp.put("apple", 15);

    cout << mp.get("apple") << '\n';     // 15

    mp.remove("banana");

    cout << boolalpha << mp.contains("banana") << '\n';  // false

    return 0;
}
