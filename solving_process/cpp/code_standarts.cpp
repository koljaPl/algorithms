#include <bits/stdc++.h>
using namespace std;

// ======================
// Types
// ======================

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

// ======================
// Constants
// ======================

const int INF = 1e9;
const ll INF64 = 1e18;
const int MOD = 1e9 + 7;

// ======================
// Macros
// ======================

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define sz(x) (int)(x).size()

// ======================
// Fast IO
// ======================

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ======================
// Solve
// ======================

void solve() {
    // write solution here
}

// ======================
// Main
// ======================

int main() {
    fast_io();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// Writing solutions in files:

#include <cstdio>
using namespace std;

int main() {
    freopen("template.in", "r", stdin);
    freopen("template.out", "w", stdout);
}

// or 

#include <fstream>
using namespace std;
    
int main() {
    ifstream fin("template.in");
    ofstream fout("template.out");
}

// Helper functions for input and output for IO:
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// slightly faster input and output:
#include <cstdio>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	/*
	 * %d specifies that a value of type int is being input.
	 * To input a 64-bit (long long) number,
	 * use %lld instead (some OJs might need %I64 instead).
	 * Many other specifiers are also available; see link for more details.
	 *
	 * Be sure to add a & character (address-of operator) when using
	 * scanf, UNLESS you are inputing a string with %s.
	 *
	 * It is possible to input multiple values at a time as shown below.
	 */
	scanf("%d %d %d", &a, &b, &c);

	/*
	 * Specifiers for printf are mostly the same as those used
	 * by scanf, with the notable exception of floating-point numbers.
	 * Use a backslash character followed by the lowercase
	 * letter n to denote a newline.
	 * The address-of operator (&) is not used here.
	 */
	printf("The sum of these three numbers is %d\n", a + b + c);
}