#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;

    vector<pair<int, int>> moves;

    std::function<void(int, int, int, int)> hanoi = [&](int count, int start, int end, int aux) {
        if (count == 1) {
            moves.emplace_back(start, end);
            return;
        }

        hanoi(count - 1, start, aux, end);

        moves.emplace_back(start, end);
        
        hanoi(count - 1, aux, end, start);
    };

    hanoi(n, 1, 3, 2);

    cout << moves.size() << "\n";

    for (auto &move : moves) {
        cout << move.first << " " << move.second << "\n";
    }

    return 0;
}
