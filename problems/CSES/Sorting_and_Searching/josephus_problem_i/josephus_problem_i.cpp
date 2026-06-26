#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> circle;
    for (int i = 1; i < n + 1; i++) circle.push_back(i);

    vector<int> res;

    while (!circle.empty()) {
        int first = circle.front();
        circle.pop_front();
        circle.push_back(first);

        if (circle.empty()) break;

        int second = circle.front();
        circle.pop_front();

        res.push_back(second);
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";

    cout << "\n";

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            v.push_back(v[i]);
        } else {
            cout << v[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}
