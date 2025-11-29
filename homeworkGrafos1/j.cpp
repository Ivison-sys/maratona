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

void dfs(Grafo &g, int v, vi &antecessor, vector<int> &marcado, stack<int> &top){
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
    marcado[v] = 2;
    top.push(v);
    return;
}

void buscaProfundidade(Grafo &g, stack<int> &top){
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
        adj[--a].push_back(--b);
    }

    Grafo g(v, adj);
    stack<int> t;
    buscaProfundidade(g, t);
    
    if(cicloEncontrado){
        cout << "IMPOSSIBLE" nl;
    } else{
        while(!t.empty()){
            cout << t.top() + 1 << " ";
            t.pop();
        }
        cout nl;
    }
    
    return 0; 
}