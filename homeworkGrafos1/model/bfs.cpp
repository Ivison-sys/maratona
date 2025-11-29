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

void bfs(Grafo &g){
    vector<bool> marcado(g.vertices.size(), false);
    vi antecessor(g.vertices.size(), -1);
    queue<int> fila;
    int v;
    for(int i = 0; i < g.vertices.size(); i++){
        if(!marcado[i]){
            fila.push(i); marcado[i] = true;
            while(!fila.empty()){
                v = fila.front(); fila.pop();
                for(auto &u: g.adjacentes[v]){
                    if(!marcado[u]){
                        marcado[u] = true;
                        antecessor[u] = v;
                        fila.push(u);
                    }
                }
            }
        }
    }

    cout nl;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV, qA; cin >> qV >> qA;
    vi v(qV); vii adj(qV);

    for(int i = 0; i < qV; i++) v[i] = i;

    int a, b;
    for(int i = 0; i < qA; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    Grafo g(v, adj);
    vi top; top.reserve(g.vertices.size());
    bfs(g);

    for(int i = top.size()-1; i >= 0; i--){
        cout << top[i] << " ";
    }
    cout nl;
    
    return 0; 
}