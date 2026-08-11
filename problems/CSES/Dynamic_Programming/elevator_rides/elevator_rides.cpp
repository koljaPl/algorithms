#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll maxWeight;
    cin >> n >> maxWeight;

    vector<ll> weights(n);
    for (ll &w : weights) cin >> w;

    int totalMasks = 1 << n;

    vector<int> rides(totalMasks, n + 1);
    vector<ll> lastWeight(totalMasks, 0);

    rides[0] = 1;

    vector<ll> weightByBit(totalMasks, 0);

    for (int person = 0; person < n; person++) {
        weightByBit[1 << person] = weights[person];
    }

    for (int mask = 1; mask < totalMasks; mask++) {
        int bestRides = n + 1;
        ll bestLastWeight = 0;

        int remaining = mask;

        while (remaining) {
            int bit = remaining & -remaining;

            int previousMask = mask ^ bit;
            ll weight = weightByBit[bit];

            int candidateRides = rides[previousMask];
            ll candidateWeight = lastWeight[previousMask] + weight;

            if (candidateWeight > maxWeight) {
                candidateRides++;
                candidateWeight = weight;
            }

            if (
                candidateRides < bestRides ||
                (
                    candidateRides == bestRides &&
                    candidateWeight < bestLastWeight
                )
            ) {
                bestRides = candidateRides;
                bestLastWeight = candidateWeight;
            }

            remaining ^= bit;
        }

        rides[mask] = bestRides;
        lastWeight[mask] = bestLastWeight;
    }

    cout << rides[totalMasks - 1] << '\n';

    return 0;
}
