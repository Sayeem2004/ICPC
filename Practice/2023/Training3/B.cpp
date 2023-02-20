// Solved by Mohammad Khan & Pablo Raigoza
#include <bits/stdc++.h>
using namespace std;

bool dfs(int x, int y, int gx, int gy, vector<vector<int>> &G, vector<vector<bool>> &V, int mask) {
    if (x == gx && y == gy) return true;
    if (V[x][y]) return false;
    V[x][y] = true;

    int n = G.size(), m = G[0].size();
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (V[nx][ny]) continue;
        if ((mask & (1 << G[nx][ny])) && dfs(nx, ny, gx, gy, G, V, mask)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    int x1, y1; cin >> x1 >> y1; x1--; y1--;
    int x2, y2; cin >> x2 >> y2; x2--; y2--;

    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < m; q++) {
            cin >> G[i][q]; G[i][q]--;
        }
    }

    int mn = 100;
    for (int i = 0; i < 1024; i++) {
        vector<vector<bool>> V(n, vector<bool>(m, false));
        if ((i & (1 << G[x1][y1])) && dfs(x1, y1, x2, y2, G, V, i)) {
            mn = __builtin_popcount(i);
        }
    }

    cout << mn << "\n";
}
