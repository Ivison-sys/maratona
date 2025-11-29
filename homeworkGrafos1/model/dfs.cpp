#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
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

bool cicloEncontrado = false;
vi ciclo;

void caminhoCiclo(int inicio, int fim, vi &antecessor) {
    vi temp;
    temp.push_back(inicio);

    int atual = fim;
    while (atual != inicio) {
        temp.push_back(atual);
        atual = antecessor[atual];
    }
    temp.push_back(inicio);

    reverse(temp.begin(), temp.end());
    ciclo = temp;
}

void dfs(Grafo &g, int v, vi &antecessor, vector<int> &marcado, vi &top){
    marcado[v] = 1;
    for(auto &u: g.adjacentes[v]){
        if(marcado[u] == 0){
            antecessor[u] = v;
            dfs(g, u, antecessor, marcado, top);
        } else if(marcado[u] == 1){
            if(!cicloEncontrado){
                cicloEncontrado = true;
                caminhoCiclo(u, v, antecessor);
                return;
            }
        }
    }
    top.push_back(v);
    return;
}

void buscaProfundidade(Grafo &g, vi &top){
    vector<int> marcado(g.vertices.size(), 0);
    vi antecessor(g.vertices.size(), -1);
    for(auto &x: g.vertices){
        if(marcado[x] == 0) dfs(g, x, antecessor, marcado, top);
    }

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
        a--; b--;
        adj[a].push_back(b);
    }

    Grafo g(v, adj);
    vi top; top.reserve(g.vertices.size());
    buscaProfundidade(g, top);
    
    if(!cicloEncontrado){
        cout << "IMPOSSIBLE" nl;
    } else{
        cout << ciclo.size() nl;
        for(int i = 0; i < ciclo.size(); i++){
            cout << ciclo[i]+1;
            if(i < ciclo.size()-1) cout << " "; 
        }
        cout nl;
    }
    cout nl;
    
    return 0; 
}