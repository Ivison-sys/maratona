#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
 
int qC, qL;

const int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
const int dy[] = {1, -1, 2, 2, -1, 1, -2, -2};

bool valid(int x, int y){
    return x >= 0 && x < qL && y >= 0 && y < qC;
}

int oc = 0;

void bfs(pair<int, int> inicio, pair<int, int> fim){
    map<pair<int, int>, bool> marcado;
    queue<pair<int, int>> fila;
    pair<int,int> v;
    map<pair<int, int>, int> dist;

    fila.push(inicio); marcado[inicio] = true;
    dist[inicio] = 0;
    while(fila.size()>0){
        v = fila.front(); fila.pop();
        if(v == fim){
            oc = dist[v];
            return;
        }
        for(int i = 0; i < 8; i++){
            int aux = v.first +dx[i], auy = v.second + dy[i];
            if(valid(aux, auy)){
                pair<int, int> u = {aux, auy};
                if(!marcado[u]){
                    marcado[u] = true;
                    dist[u] = dist[v] + 1;
                    fila.push(u);
                }
            }
        }
    }

    cout nl;
}

pair<int, int> converter(string pos){
    return {pos[0] - 97, pos[1] - 49};
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    qC = 8; qL = 8;
    string p1, p2;
    while(cin >> p1){
        cin >> p2;
        auto inicio = converter(p1), fim = converter(p2);
        bfs(inicio, fim);
        cout << "To get from " << p1 << " to " << p2 << " takes " << oc << " knight moves." nl;
        oc = 0;
    }
    
    return 0; 
}