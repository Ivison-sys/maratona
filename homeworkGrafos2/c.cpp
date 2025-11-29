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
    
    int qV, qA; cin >> qV >> qA;

    DSU dsu(qV);

    vector<tuple<int,int,int>> arestas(qA);
    for(auto &[c,u,v] : arestas){
        cin >> u >> v;
        --u; --v; 
        c = 0;
    }

    int t; cin >> t;
    vi arestasRemovidas(t);
    for(auto &x : arestasRemovidas){
        cin >> x; 
        --x;
        auto [c,u,v] = arestas[x];
        arestas[x] = {-1,u,v};
    }

    int qCmp = qV;

    
    for(auto &[c,u,v] : arestas){
        if(c == -1) continue;
        if(dsu.find(u) != dsu.find(v)){
            dsu.join(u,v);
            --qCmp;
        }
    }

    vi resp; resp.reserve(t);

   
    for(int i = t - 1; i >= 0; i--){
        auto &[c,u,v] = arestas[arestasRemovidas[i]];
        resp.push_back(qCmp);
        if(dsu.find(u) != dsu.find(v)){
            dsu.join(u,v);
            --qCmp;
        }
    }

    // imprime na ordem correta
    for(int i = resp.size() - 1; i >= 0; i--){
        cout << resp[i] << " ";
    }
    cout nl;

    return 0; 
}
