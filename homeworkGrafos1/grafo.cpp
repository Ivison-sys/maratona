#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>; using vii = vector<vector<int>>;
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
    vi vertices;
    vii adjacentes;
    vector<vector<pair<int, int>>> pesos;
    bool cicloEncontrado;
    vi ciclo;
    stack<int> topsort;

    Grafo(vi vertices, vii adjacentes, vector<vector<pair<int,int>>> pesos = {{}}){
        this->vertices = vertices;
        this->adjacentes = adjacentes;
        this->pesos = pesos;
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

};




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
  
    
    return 0; 
}