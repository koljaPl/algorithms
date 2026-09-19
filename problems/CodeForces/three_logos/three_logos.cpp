#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Rect {
    int w, h;
    char ch;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Rect> rs(3);
    rs[0].ch = 'A';
    rs[1].ch = 'B';
    rs[2].ch = 'C';

    int total_area = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> rs[i].w >> rs[i].h;
        total_area += rs[i].w * rs[i].h;
    }

    int n = round(sqrt(total_area));
    if (n * n != total_area) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> p = {0, 1, 2};
    do {
        for (int mask = 0; mask < 8; ++mask) {
            vector<Rect> cur(3);
            for (int i = 0; i < 3; ++i) {
                cur[i] = rs[p[i]];

                if (mask & (1 << i)) 
                    swap(cur[i].w, cur[i].h);
            }

            if (cur[0].w == n && cur[1].w == n && cur[2].w == n &&
                cur[0].h + cur[1].h + cur[2].h == n) {
                
                cout << n << "\n";
                for (int i = 0; i < 3; ++i) {
                    for (int row = 0; row < cur[i].h; ++row) {
                        cout << string(n, cur[i].ch) << "\n";
                    }
                }

                return 0;
            }

            if (cur[0].w == n && (n - cur[0].h > 0)) {
                int rem_h = n - cur[0].h;
                if (cur[1].h == rem_h && cur[2].h == rem_h && cur[1].w + cur[2].w == n) {
                    cout << n << "\n";

                    for (int row = 0; row < cur[0].h; ++row) {
                        cout << string(n, cur[0].ch) << "\n";
                    }

                    for (int row = 0; row < rem_h; ++row) {
                        cout << string(cur[1].w, cur[1].ch) << string(cur[2].w, cur[2].ch) << "\n";
                    }
                    
                    return 0;
                }
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << -1 << "\n";

    return 0;
}
