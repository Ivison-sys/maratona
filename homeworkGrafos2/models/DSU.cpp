#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
const int INF = 1e9;

class DSU{
    public:
        vi pai, size;

        DSU(int n){
            pai.resize(n);
            size.assign(n, 1);
            for(int i = 0; i < n; i++) pai[i] = i;
        
        }

        int find(int u){
            if(u == this->pai[u]) return u;
            return this->pai[u] = this->find(this->pai[u]);
        }

        void join(int u, int v){
            u = this->find(u);
            v = this->find(v);

            if(u == v) return;
            if(this->size[u] < this->size[v]) swap(u, v);

            pai[v] = u;
            this->size[u] += this->size[v];
        }
};

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int qV, qA;
    cin >> qV >> qA;
    
    DSU dsu(qV);

    vector<tuple<int, int, int>> arestas(qA);
    for(auto &[custo, u, v]: arestas){
        cin >> u >> v >> custo;
    }

    sort(arestas.begin(), arestas.end());

    ll totalCust = 0;

    for(auto &[custo, u, v]: arestas){
        if(dsu.find(u) != dsu.find(v)){
            dsu.join(u,v);
            totalCust += custo;
        }
    }

    cout << totalCust nl;
    return 0; 
}