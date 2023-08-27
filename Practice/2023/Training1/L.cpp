// Solved by Mohammad Khan
#include <bits/stdc++.h>
using namespace std;

pair<int, bool> dfs(int v, int p, int g, vector<vector<int>> &A) {
    int ans = 0, fnd = false;

    for (int u : A[v]) {
        if (u == p) continue;
        if (u == g) return {1, true};

        auto [a, b] = dfs(u, v, g, A);
        if (b) ans += a+1;
        else ans += a+2;
        fnd |= b;
    }

    return {ans, fnd || v == g};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<vector<int>> A(n);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }

    cout << dfs(0, -1, x-1, A).first << "\n";
}
