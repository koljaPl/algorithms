#include <bits/stdc++.h>
using namespace std;

// Sieve Of Eratosthenes:
//
// Time Complexity:
// O(n log log n)
//
// Space Complexity:
// Memory: O(n)

vector<int> sieve_of_eratosthenes(int n) {
    if (n < 2) {
        return {};
    }

    vector<bool> is_prime(n + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    int prime = 2;

    while (prime * prime <= n) {
        if (is_prime[prime]) {
            for (int multiple = prime * prime;
                 multiple <= n;
                 multiple += prime) {

                is_prime[multiple] = false;
            }
        }

        prime++;
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
