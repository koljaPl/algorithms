#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAX_POS = 2000;
bool visible[MAX_POS][MAX_POS];

int main_v1() {
    setIO("billboard");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
        
		x1 += MAX_POS / 2;
		y1 += MAX_POS / 2;
		x2 += MAX_POS / 2;
		y2 += MAX_POS / 2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) visible[x][y] = i < 2;
		}
	}

	int res = 0;
	for (int x = 0; x < MAX_POS; x++) {
		for (int y = 0; y < MAX_POS; y++) res += visible[x][y];
	}

	cout << res << "\n";

    return 0;
}

struct Rect {
	int x1, y1, x2, y2;
	void read() { cin >> x1 >> y1 >> x2 >> y2; }
	int area() { return (y2 - y1) * (x2 - x1); }
};

int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main() {
    setIO("billboard");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Rect a, b, t;
	a.read();
	b.read();
	t.read();

	cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << "\n";

    return 0;
}
