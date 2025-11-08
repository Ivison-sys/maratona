#include <bits/stdc++.h>
#define nl << '\n'
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    
    for(auto &x: board){
        for(auto &y: x) cin >> y;
    }

    int D = n + m - 1;
    vector<int> sumDiag1(D, 0), sumDiag2(D, 0); 
    int p = m - 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sumDiag1[(i - j) + p] += board[i][j];
            sumDiag2[i + j] += board[i][j];
        }
    }

    int resp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value = sumDiag1[(i - j) + p] + sumDiag2[i + j] - board[i][j];
            if (value > resp) resp = value;
        }
    }

    cout << resp nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; 
    cin >> tc; 
    while (tc--) solve();
    return 0;
}
