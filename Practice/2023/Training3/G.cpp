// Solved by Mohammad Khan & Pablo Raigoza
#include <bits/stdc++.h>
using namespace std;

array<array<long long, 3>, 3> revA(long long n) {
    array<long long, 3> row1 = {0, 1, 0};
    array<long long, 3> row2 = {1, 0, 0};
    array<long long, 3> row3 = {0, 0, 1};
    return {row1, row2, row3};
}

array<array<long long, 3>, 3> revB(long long n) {
    array<long long, 3> row1 = {1, 0, 0};
    array<long long, 3> row2 = {0, -1, n-1};
    array<long long, 3> row3 = {0, 0, 1};
    return {row1, row2, row3};
}

array<array<long long, 3>, 3> revC(long long n) {
    array<long long, 3> row1 = {0, -1, n-1};
    array<long long, 3> row2 = {-1, 0, n-1};
    array<long long, 3> row3 = {0, 0, 1};
    return {row1, row2, row3};
}

array<array<long long, 3>, 3> revD(long long n) {
    array<long long, 3> row1 = {-1, 0, n-1};
    array<long long, 3> row2 = {0, 1, 0};
    array<long long, 3> row3 = {0, 0, 1};
    return {row1, row2, row3};
}

array<array<long long, 3>, 3> multiply(array<array<long long, 3>, 3> a, array<array<long long, 3>, 3> b) {
    array<array<long long, 3>, 3> c;

    for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (long long k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

array<long long, 3> multiply(array<array<long long, 3>, 3> a, array<long long, 3> b) {
    array<long long, 3> c;

    for (long long i = 0; i < 3; i++) {
        c[i] = 0;
        for (long long j = 0; j < 3; j++) {
            c[i] += a[i][j] * b[j];
        }
    }

    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, m; cin >> n >> m;
    array<long long, 3> row1 = {1, 0, 0};
    array<long long, 3> row2 = {0, 1, 0};
    array<long long, 3> row3 = {0, 0, 1};
    array<array<long long, 3>, 3> curr = {row1, row2, row3};

    for (long long i = 0; i < m; i++) {
        char c; cin >> c;

        if (c == 'q') {
            long long x, y; cin >> x >> y;
            array<long long, 3> p = {x-1, y-1, 1};
            array<long long, 3> ans = multiply(curr, p);
            cout << ans[0]*n + ans[1]+1<< "\n";
        } else if (c == 'r') {
            char t; cin >> t;

            if (t == 'a') curr = multiply(curr, revA(n));
            else if (t == 'b') curr = multiply(curr, revB(n));
            else if (t == 'c') curr = multiply(curr, revC(n));
            else if (t == 'd') curr = multiply(curr, revD(n));
        }
    }
}
