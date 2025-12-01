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
    vector<vector<pair<int, int>>> pesos;
    vector<tuple<int, int, int>> arestas;

    Grafo(int qV, int qA){
        this->tamanho = qV;
        this->pesos.resize(qV);
        vi tamanhos(qV);
        for(auto &x: tamanhos) cin >> x;
        int cont = 0;
        for(int i = 0; i < qV; i++){
            cont = 0;
            if(i == qV - 1) break;
            for(int p = i+1; p < qV && cont < qA; p++){
                this->pesos[i].push_back({p, abs(tamanhos[i] - tamanhos[p])});
                cont++;
            }
        }
        
    }

    int dijkstra(int comeco = 0, int fim = -1){
        vi dist(this->tamanho, INF);
        vi antecessor(this->tamanho, -1);

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        dist[comeco] = 0;
        minHeap.push({0,comeco});
    
        while(!minHeap.empty()){
            auto [distancia, origem] = minHeap.top();
            minHeap.pop();
    
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
        return dist[this->tamanho - 1];
    }


};

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qV, qA; cin >> qV >> qA;
    Grafo g(qV, qA);
    
    cout << g.dijkstra() nl;
    
    return 0; 
}