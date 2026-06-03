#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr(7);
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1] << "\n";

    return 0;
}
