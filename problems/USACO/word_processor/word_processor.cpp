#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("word");

    int n, k;
    cin >> n >> k;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }

    string current = "";
    int cur_nonspace = 0;
    
    for (const string& w : words) {
        if (current.empty()) {
            current = w;
            cur_nonspace = w.length();
        } 
        else if (cur_nonspace + (int)w.length() <= k) {
            current += " " + w;
            cur_nonspace += w.length();
        } 
        else {
            cout << current << "\n";
            current = w;
            cur_nonspace = w.length();
        }
    }

    if (!current.empty()) {
        cout << current << "\n";
    }

    return 0;
}
