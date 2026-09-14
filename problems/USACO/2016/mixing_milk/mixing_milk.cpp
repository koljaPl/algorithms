#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3;
const int TURN_NUM = 100;

int main() {
    setIO("mixmilk");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> capacity(N);
	vector<int> milk(N);
	for (int i = 0; i < N; i++) cin >> capacity[i] >> milk[i];

	for (int i = 0; i < TURN_NUM; i++) {
		int bucket1 = i % N;
		int bucket2 = (i + 1) % N;

		int amt = min(milk[bucket1], capacity[bucket2] - milk[bucket2]);

		milk[bucket1] -= amt;
		milk[bucket2] += amt;
	}

	for (int m : milk) cout << m << '\n';

    return 0;
}
