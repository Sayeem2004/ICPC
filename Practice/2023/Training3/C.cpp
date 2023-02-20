// Solved by Mohammad Khan & Pablo Raigoza
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, m; cin >> n >> m;
    vector<long long> V(n), P(n+1);

    for (long long i = 0; i < n; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    for (long long i = 0; i < n; i++) {
        P[i+1] = P[i] + V[i];
    }

    for (long long i = 0; i < m; i++) {
        long long x; cin >> x;
        auto itr = upper_bound(V.begin(), V.end(), x);
        long long pos = itr - V.begin();
        cout << P[pos] + x * (n - pos) << "\n";
    }
}
