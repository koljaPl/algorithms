#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    vector<int> starts, ends;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        starts.push_back(a);
        ends.push_back(b);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int res = 0, count = 0;
    int left = 0, right = 0;

    while (left < n) {
        if (starts[left] < ends[right]) {
            count++;
            left++;
        } else {
            count--;
            right++;
        }
        res = max(res, count);
    }

    cout << res << "\n";

    return 0;
}

int main_v2() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        events.emplace_back(a, 1);
        events.emplace_back(b, -1);
    }

    sort(events.begin(), events.end());

    int res = 0, count = 0;
    for (auto& event : events) {
        count += event.second;
        res = max(res, count);
    }

    cout << res << "\n";

    return 0;
}
