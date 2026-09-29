#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Rect {
    int x1, y1, x2, y2;

    int area() const {
        return (x2 - x1) * (y2 - y1);
    }

    bool contains(int x, int y) const {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
};

int main() {
    setIO("billboard");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Rect target, cover;
    cin >> target.x1 >> target.y1 >> target.x2 >> target.y2;
    cin >> cover.x1 >> cover.y1 >> cover.x2 >> cover.y2;

    int corners = 0;
    if (cover.contains(target.x1, target.y1)) corners++;
    if (cover.contains(target.x1, target.y2)) corners++;
    if (cover.contains(target.x2, target.y1)) corners++;
    if (cover.contains(target.x2, target.y2)) corners++;

    if (corners < 2) {
        cout << target.area() << "\n";
    } else if (corners == 4) {
        cout << 0 << "\n";
    } else {
        int inter_x = max(0, min(target.x2, cover.x2) - max(target.x1, cover.x1));
        int inter_y = max(0, min(target.y2, cover.y2) - max(target.y1, cover.y1));
        int inter_area = inter_x * inter_y;

        cout << target.area() - inter_area << "\n";
    }

    return 0;
}
