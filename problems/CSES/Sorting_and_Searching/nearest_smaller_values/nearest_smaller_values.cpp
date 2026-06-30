#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        while (!st.empty() && st.top().first >= x)
            st.pop();

        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top().second << " ";

        st.push({x, i});
    }
}
