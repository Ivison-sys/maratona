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

int converterChar(char a){
    return a - 97;
}

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
                return;
                caminhoCiclo(u, v, antecessor);
            }
        }
    }
    marcado[v] = 2;
    if(!g.adjacentes[v].empty() || antecessor[v] != -1) top.push(v);
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
    int qV = 26, qA; cin >> qA;
    // cout << (int) 'z';
    vi v(qV); vii adj(qV);
    map<int, bool> alfabeto;

    for(int i = 0; i < qV; i++) v[i] = i;

    string inp;
    for(int i = 0; i < qA; i++){
        cin >> inp;
        for(int w = 0; w < inp.size() - 1; w ++){
            if(inp[w] != inp[w+1]) adj[converterChar(inp[w])].push_back(converterChar(inp[w+1]));
        }    
    }

    Grafo g(v, adj);
    stack<int> t;
    buscaProfundidade(g, t);
    
    if(cicloEncontrado){
        cout << "NAO" nl;
    } else{
        cout << "SIM" nl;
        while(!t.empty()){
            cout << (char) (t.top() + 97);
            alfabeto[t.top() + 97] = true;
            t.pop();
        }
        for(int i = 97; i <= 122; i++){
            if(!alfabeto[i]) cout << (char) i;
        }
        cout nl;
    }
    
    return 0; 
}