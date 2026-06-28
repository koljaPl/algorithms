#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
    ll a;
    ll b;
    int i;

    bool operator<(const P& other) const {
        if (a != other.a)
            return a < other.a;
        if (b != other.b)
            return b < other.b;
        return i < other.i;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<P> customers;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(customers.begin(), customers.end());
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> rooms;

    vector<ll> allocation_example(n, 0);
    ll room_count = 0;

    for (P customer : customers) {
        ll arrival = customer.a;
        ll departure = customer.b;
        ll idx = customer.i;

        ll room_id;

        if (!rooms.empty() && rooms.top().first < arrival) {
            auto [last_departure, free_room] = rooms.top();
            rooms.pop();

            room_id = free_room;
        } else {
            room_count++;
            room_id = room_count;
        }

        allocation_example[idx] = room_id;
        rooms.push({departure, room_id});
    }
    
    cout << room_count << "\n";

    for (ll pos : allocation_example) 
        cout << pos << " ";
    cout << "\n";

    return 0;
}
