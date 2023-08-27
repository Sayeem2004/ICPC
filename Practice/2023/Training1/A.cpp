// Solved by Mohammad Khan
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    cout << min(15, (3000+n-1)/n) << "\n";
}
