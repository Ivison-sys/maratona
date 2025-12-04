#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
const int INF = 1e9;

typedef struct{
    int inicio;
    int fim;
    ll valor;
} Tarefa;

ll sol(int i, vector<ll> &dp){
    if( i == -1) return 0;
    return dp[i];
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int q; cin >> q;
    vector<Tarefa> tarefas(q);
    vi antecessor(q); vector<ll> dp(q);
    vi fins(q);

    for(auto &x: tarefas) cin >> x.inicio >> x.fim >> x.valor;

    sort(tarefas.begin(), tarefas.end(), [](const Tarefa &a, const Tarefa &b){
        if(a.fim != b.fim) return a.fim < b.fim;
        return a.inicio < b.inicio;
    });

    for(int i = 0; i < q; i++) fins[i] = tarefas[i].fim;

    for(int i = 0; i < q; i++){
       int j = upper_bound(fins.begin(), fins.end(), tarefas[i].inicio - 1) - fins.begin() - 1;
       antecessor[i] = j;
    }
    ll valorMax = -1;
    for(int i = 0; i < q; i++){
        dp[i] = max(sol(antecessor[i], dp) + tarefas[i].valor, sol(i-1, dp));
        valorMax = max(valorMax, dp[i]);
    }

    cout << valorMax nl;


    
    return 0; 
}