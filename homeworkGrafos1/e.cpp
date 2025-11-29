#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
const int INF = 1e9;

class Grafo {
public:
    vi vertices;
    vii adjacentes;
    vector<vector<pair<int, int>>> pesos;

    Grafo(vi vertices, vii adjacentes, vector<vector<pair<int,int>>> pesos = {{}}){
        this->vertices = vertices;
        this->adjacentes = adjacentes;
        this->pesos = pesos;
    }
    
};

vi bfs(Grafo &g){
    vector<bool> marcado(g.vertices.size(), false);
    vi antecessor(g.vertices.size(), -1);
    vi color(g.vertices.size(), -1);
    queue<int> fila;
    int v;
    for(int i = 0; i < g.vertices.size(); i++){
        if(!marcado[i]){
            if(antecessor[i] == -1) color[i] = 0;
            fila.push(i); marcado[i] = true;
            while(!fila.empty()){
                v = fila.front(); fila.pop();
                for(auto [u, p]: g.pesos[v]){
                    if(!marcado[u]){
                        marcado[u] = true;
                        antecessor[u] = v;
                        if(p%2 == 0) color[u] = color[v];
                        else color[u] = (color[v] == 1) ? 0 : 1;
                        fila.push(u);
                    }
                }
            }
        }
    }

    return color;

}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV, qA, N; cin >> qV;
    qA = qV-1;
    vi v(qV); vii adj(qV); vector<vector<pair<int, int>>> p(qV);

    for(int i = 0; i < qV; i++) v[i] = i;
    
    int a, b, m;

    for(int i = 0; i < qA; i++){
        cin >> a >> b >> m;
        adj[--a].push_back(--b);
        p[a].push_back({b,m});
        adj[b].push_back(a);
        p[b].push_back({a,m});
    }

    Grafo g(v, adj, p);
    auto color = bfs(g);
    for(auto &x: color){
        cout << x nl;
    }

    return 0; 
}