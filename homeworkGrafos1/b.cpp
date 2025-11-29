#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;

class Grafo {
public:
    vi vertices;
    vii adjacentes;

    Grafo(vi vertices, vii adjacentes){
        this->vertices = vertices;
        this->adjacentes = adjacentes;
    }
};

int bfs(Grafo &g, int inicio){
    vector<bool> marcado(g.vertices.size(), false);
    vi dist(g.vertices.size(), -1);
    vi antecessor(g.vertices.size(), -1);
    queue<int> fila;
    int v, maior = 0;
    if(dist[inicio] == -1){
        fila.push(inicio); marcado[inicio] = true;
        dist[inicio] = 0; 
        while(fila.size()>0){
            v = fila.front(); fila.pop();
            maior = max(maior, dist[v]);
            for(auto &u: g.adjacentes[v]){
                if(dist[u] == -1){
                    dist[u] = dist[v] + 1;
                    antecessor[u] = v;    
                    fila.push(u);
                }
            }
        }   
    }
    return maior;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV; cin >> qV;
    int qA = qV;
    vi v(qV); vii adj(qV);

    for(int i = 0; i < qV; i++) v[i] = i;

    int a, b;
    for(int i = 0; i < qA; i++){
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        
    }

    Grafo g(v, adj);
    for(auto &x: g.vertices){
        auto qb = bfs(g,x);
        cout << qb << " ";

    }
    cout nl;
    
    return 0; 
}