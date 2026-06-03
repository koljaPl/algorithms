#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    setIO("promote");

    int bronze_before, bronze_after;
    int silver_before, silver_after;
    int gold_before, gold_after;
    int platinum_before, platinum_after;

    cin >> bronze_before >> bronze_after;
    cin >> silver_before >> silver_after;
    cin >> gold_before >> gold_after;
    cin >> platinum_before >> platinum_after;

    int gold_to_platinum = platinum_after - platinum_before;
    int silver_to_gold = gold_after - gold_before + gold_to_platinum;
    int bronze_to_silver = silver_after - silver_before + silver_to_gold;

    cout << bronze_to_silver << "\n" << silver_to_gold << "\n" << gold_to_platinum << "\n";

    return 0;
}
