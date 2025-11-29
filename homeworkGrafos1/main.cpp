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

pair<bool, vi> bfs(Grafo &g){
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
                for(auto &u: g.adjacentes[v]){
                    if(!marcado[u]){
                        marcado[u] = true;
                        antecessor[u] = v;
                        color[u] = (color[v] == 1) ? 0 : 1;
                        fila.push(u);
                    }
                    else if(color[u] == color[v]){
                        return {false, color};
                    }
                }
            }
        }
    }

    return {true, color};

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
        adj[b].push_back(a);
    }

    Grafo g(v, adj);
    auto [valid, color] = bfs(g);
    if(valid){
        for(int i = 0; i < color.size(); i++){
            if(color[i] == 0) cout << 1;
            else if(color[i] == 1) cout << 2;

            if(i < color.size() - 1) cout << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    cout nl;
    return 0; 
}