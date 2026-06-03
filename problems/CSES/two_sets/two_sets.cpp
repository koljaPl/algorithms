#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n * (n + 1) / 2 % 2 == 0) {
        cout << "YES\n";
        vector<ll> a, b;

        if (n % 4 == 0) {
            ll l = 1, r = n;

            while (l < r) {
                a.push_back(l);
                a.push_back(r);
                b.push_back(l + 1);
                b.push_back(r - 1);

                l += 2;
                r -= 2;
            }
        } else {
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);

            ll l = 4, r = n;

            while (l < r) {
                a.push_back(l);
                a.push_back(r);
                
                b.push_back(l + 1);
                b.push_back(r - 1);

                l += 2;
                r -= 2;
            }
        }

        cout << a.size() << "\n";
        for (auto value : a) { 
            cout << value << " ";
        }

        cout << "\n";

        cout << b.size() << "\n";
        for (auto value : b) {
            cout << value << " ";
        }

        return 0;

    } else {
        cout << "NO\n";
        return 0;
    }

    return 0;
}
