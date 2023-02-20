// Solved by Mohammad Khan
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    map<int, int> M;

    M['a'] = '2'; M['b'] = '2'; M['c'] = '2';
    M['d'] = '3'; M['e'] = '3'; M['f'] = '3';
    M['g'] = '4'; M['h'] = '4'; M['i'] = '4';
    M['j'] = '5'; M['k'] = '5'; M['l'] = '5';
    M['m'] = '6'; M['n'] = '6'; M['o'] = '6';
    M['p'] = '7'; M['q'] = '7'; M['r'] = '7'; M['s'] = '7';
    M['t'] = '8'; M['u'] = '8'; M['v'] = '8';
    M['w'] = '9'; M['x'] = '9'; M['y'] = '9'; M['z'] = '9';

    map<string, int> A;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string key = "";
        for (int q = 0; q < s.size(); q++) {
            key += M[s[q]];
        }
        A[key]++;
    }

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        cout << A[s] << "\n";
    }
}
