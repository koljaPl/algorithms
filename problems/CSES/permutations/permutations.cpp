#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
    } else if (n < 4) {
        cout << "NO SOLUTION" << "\n";
    } else {
        vector<int> res;
        
        for (int i = 2; i < n + 1; i += 2) {
            res.push_back(i);
        }
        
        for (int i = 1; i < n + 1; i += 2) {
            res.push_back(i);
        }

        for (int num : res) {
            std::cout << num << " "; 
        }
    }

    return 0;
}
