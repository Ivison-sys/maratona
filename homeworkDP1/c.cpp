#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vii = vector<vector<int>>;
const int INF = 1e9;

string a, b;

vector<vector<char>> caminho;

int best(int i, int j, vii &dp){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]){
        dp[i][j] = 1 + best(i-1, j-1, dp);
        caminho[i][j] = 'D';
    } 
    else {
        int cima = best(i-1, j, dp);
        int esq  = best(i, j-1, dp);
        if(cima >= esq){
            dp[i][j] = cima;
            caminho[i][j] = 'U';
        } else {
            dp[i][j] = esq;
            caminho[i][j] = 'L';
        }
    }

    return dp[i][j];
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vii dp(n, vi(m, -1));
    caminho.assign(n, vector<char>(m, 'X'));

    best(n - 1, m - 1, dp);

    string resp = "";
    int i = n - 1, j = m - 1;

    while(i >= 0 && j >= 0){
        if(caminho[i][j] == 'D'){
            resp += a[i];
            i--; j--;
        }
        else if(caminho[i][j] == 'U'){
            i--;
        }
        else {
            j--;
        }
    }

    reverse(resp.begin(), resp.end());
    cout << resp nl;

    return 0; 
}
