#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("notlast");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> milk = {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int amount;

        cin >> name >> amount;
        milk[name] += amount;
    }

    set<int> unique_amounts;
    for (const auto& [name, amount] : milk)
        unique_amounts.insert(amount);

    if (unique_amounts.size() < 2) {
        cout << "Tie\n";
        return 0;
    }

    auto it = unique_amounts.begin();
    it++;
    int second_min = *it;

    vector<string> candidates;
    for (const auto& [name, amount] : milk) {
        if (amount == second_min) candidates.pb(name);
    }

    if (candidates.size() == 1) {
        cout << candidates[0] << "\n";
    } else {
        cout << "Tie\n";
    }

    return 0;
}
