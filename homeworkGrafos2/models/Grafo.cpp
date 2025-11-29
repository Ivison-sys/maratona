#include <bits/stdc++.h>
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>; using vii = vector<vector<int>>;
using pii = pair<int, int>;
const int INF = 1e9;

class Grafo {
private:
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
        this->ciclo = temp;
    }

    void dfs(int v, vi &antecessor, vi &marcado){
        marcado[v] = 1;
        for(auto &u: this->adjacentes[v]){
            if(marcado[u] == 0){
                antecessor[u] = v;
                dfs(u, antecessor, marcado);
            } else if(marcado[u] == 1){
                if(!cicloEncontrado && u != antecessor[v]){
                    cicloEncontrado = true;
                    caminhoCiclo(u, v, antecessor);
                }
            }
        }
        marcado[v] = 2;
        this->topsort.push(v);
        return;
    }

public:
    int tamanho;
    vi vertices;
    vii adjacentes;
    vector<vector<pair<int, int>>> pesos;
    vector<tuple<int, int, int>> arestas;
    bool cicloEncontrado;
    vi ciclo;
    stack<int> topsort;

    Grafo(int qV, int qA){
        this->tamanho = qV;
        vertices.resize(qV); this->adjacentes.resize(qV);
        this->pesos.resize(qV);
        
        for(int i = 0; i < qV; i++) this->vertices[i] = i;

        int a, b;
        for(int i = 0; i < qA; i++){
            cin >> a >> b; 
            a--; b--;
            this->adjacentes[a].push_back(b);
            this->adjacentes[b].push_back(a);
        }  
    }

    void buscaProfundidade(){
        vector<int> marcado(this->vertices.size(), 0);
        vi antecessor(this->vertices.size(), -1);
        for(auto &x: this->vertices){
            if(marcado[x] == 0) dfs(x, antecessor, marcado);
        }
    }

    void bfs(){
        vector<bool> marcado(this->vertices.size(), false);
        vi antecessor(this->vertices.size(), -1);
        queue<int> fila;
        int v;
        for(int i = 0; i < this->vertices.size(); i++){
            if(!marcado[i]){
                fila.push(i); marcado[i] = true;
                while(!fila.empty()){
                    v = fila.front(); fila.pop();
                    for(auto &u: this->adjacentes[v]){
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

    vi dijkstra(int comeco, int fim = -1){
        vi dist(this->vertices.size(), INF);
        vi antecessor(this->vertices.size(), -1);

        priority_queue<pair<double,int>, vector<pair<double, int>>, greater<pair<double,int>>> minHeap;
        dist[comeco] = 0;
        minHeap.push({0,comeco});
    
        while(!minHeap.empty()){
            auto [distancia, origem] = minHeap.top();
            minHeap.pop();
            if(origem == fim) return dist;
    
            if(distancia <= dist[origem]){
                for(auto &[vertice, custo]: this->pesos[origem]){
                    if(dist[vertice] > dist[origem]+custo){
                        dist[vertice] = dist[origem]+custo;
                        antecessor[vertice] = origem;
                        minHeap.push({dist[vertice], vertice});
                    }
                }
            }    
        }
        return dist;
    }

    int prim(){
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0,0});
        vector<bool> marcado(this->tamanho, false);
        int custo = 0;

        while(!minHeap.empty()){
            auto [w, u] = minHeap.top();
            minHeap.pop();

            if(!marcado[u]){
                marcado[u] = true;
                custo += w;

                for(auto &[v,c]: this->pesos[u]){
                    if(!marcado[v]){
                        minHeap.push({c,v});
                    }
                }
            }
        }
        return custo;
    }

    pair<bool, vector<ll>> bellman(int inicio){
        vector<ll> dist(this->tamanho, INF);
        dist[inicio] = 0;

        for(int rep = 0; rep < this->tamanho; rep++){
            for(auto [custo, u, v]: this->arestas){
                if(dist[v] > dist[u] + custo){
                    dist[v] = dist[u] + custo;
                }
            }
        }

        //Ciclo negativo?
        bool cicloNegativo = false;
        for(auto [custo, u, v]: this->arestas){
            if(dist[v] > dist[u] + custo){
                cicloNegativo = true;
            }
        }

        return {!cicloNegativo, dist};
    }

};

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV, qA; cin >> qV >> qA;
    Grafo g(qV, qA);
    
    
    return 0; 
}