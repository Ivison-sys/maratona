#include <bits/stdc++.h>
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>; using vii = vector<vector<int>>;
using pii = pair<int, int>;
const int INF = 1e9;

class Grafo {
public:
    int tamanho;
    vi vertices;
    vii adjacentes;
    vii adjacentes_reverso;
    vector<vector<pair<int, int>>> pesos;
    vector<tuple<int, int, int>> arestas;
    bool cicloEncontrado;
    vi ciclo;
    stack<int> topsort;

    Grafo(int qV, int qA){
        this->tamanho = qV;
        this->adjacentes.resize(qV); this->vertices.resize(qV);
        this->arestas.resize(qA); this->adjacentes_reverso.resize(qV);
        for(int i = 0; i < qV; i++) this->vertices[i] = i;

        int u, v, custo;
        for(int i = 0; i < qA; i++){
            cin >> u >> v >> custo;
            --u; --v;
            this->adjacentes[u].push_back(v);
            this->adjacentes_reverso[v].push_back(u);
            this->arestas[i] = {custo, u, v};
        }
        
    }

    vector<bool> bfs(int foco, int sentido = 0){
        vector<bool> marcado(this->vertices.size(), false);
        vi antecessor(this->vertices.size(), -1);
        queue<int> fila;
        int v;
        for(int i = foco; i < foco+1; i++){
            if(!marcado[i]){
                fila.push(i); marcado[i] = true;
                while(!fila.empty()){
                    v = fila.front(); fila.pop();
                    if(sentido == 0){
                        for(auto &u: this->adjacentes[v]){
                            if(!marcado[u]){
                                marcado[u] = true;
                                antecessor[u] = v;
                                fila.push(u);
                            }
                        }
                    } else if(sentido == 1){
                        for(auto &u: this->adjacentes_reverso[v]){
                            if(!marcado[u]){
                                marcado[u] = true;
                                antecessor[u] = v;
                                fila.push(u);
                            }
                        }
                    } 
                }
            }
        }
        return marcado;
    }

    pair<bool, vector<ll>> bellman(int inicio){
        vector<ll> dist(this->tamanho, -1e14);
        vi antecessor(this->tamanho, -1);
        dist[inicio] = 0;
        auto focoInicio = this->bfs(0, 0);
        auto focoFim = this->bfs(this->tamanho - 1, 1);

        for(int rep = 0; rep < this->tamanho - 1; rep++){
            for(auto [custo, u, v]: this->arestas){
                if(dist[u] != -1e14 && dist[v] < dist[u] + custo){
                    dist[v] = dist[u] + custo;
                    antecessor[v] = u;
                }
            }
        }

        //Ciclo postivo?
        bool cicloPositivo = false;
        for(auto [custo, u, v]: this->arestas){
            if(dist[u] != -1e14 && dist[v] < dist[u] + custo){
                if(focoInicio[v] && focoFim[v]){
                    cicloPositivo = true;
                    break;
                }
            }
        }

        return {!cicloPositivo, dist};
    }

};

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV, qA; cin >> qV >> qA;
    Grafo g(qV, qA);
    
    auto [valid, dist] = g.bellman(0);

    if(valid) cout << dist[qV-1] nl;
    else cout << -1 nl;
    
    return 0; 
}