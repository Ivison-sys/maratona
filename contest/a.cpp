#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;


int qC, qL;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool valid(vs &grid, int x, int y){
    return x >= 0 && x < qL && y >= 0 && y < qC && grid[x][y] != '#';
}

int oc = -1;

void bfs(vs &grid, pair<int, int> inicio){
    vector<vector<bool>> marcado(qL, vector<bool>(qL, false));
    queue<pair<int, int>> fila;
    pair<int,int> v;
    vii dist(qL, vi(qL, -1));

    fila.push(inicio); marcado[inicio.first][inicio.second] = true;
    dist[inicio.first][inicio.second] = 0;
    while(fila.size()>0){
        v = fila.front(); fila.pop();
        if(grid[v.first][v.second] == 'E'){
            oc = dist[v.first][v.second];
            return;
        }
        for(int i = 0; i < 4; i++){
            int aux = v.first +dx[i], auy = v.second + dy[i];
            if(valid(grid, aux, auy)){
                pair<int, int> u = {aux, auy};
                if(!marcado[aux][auy]){
                    marcado[aux][auy] = true;
                    dist[aux][auy] = dist[v.first][v.second] + 1;
                    fila.push(u);
                }
            }
        }
    }

}

void solve(vs &grid, vector<pair<int, int>> &pontos, vii &menorPossivel){
    int p = 0, limit; cin >> limit;
    limit--;
    for(auto &x: pontos){
        oc = -1;
        if(menorPossivel[x.first][x.second] != -1 && menorPossivel[x.first][x.second] <= limit){
            p++;
        } else{
            bfs(grid, x);
            if(oc <= limit && oc != -1){
                p++;
                menorPossivel[x.first][x.second] = oc;
            } 
        } 
    }
    cout << p/(double)pontos.size() nl;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8);

    int qP;
    cin >> qL >> qP;
    qC = qL;
    vs grid(qL);
    for(auto &x: grid) cin >> x;
    vector<pair<int, int>> pontos;
    
    for(int i = 0; i < qL; i++){
        for(int w = 0; w < qL; w++){
            if(grid[i][w] == '.'){
                pontos.push_back({i, w});
            }
        }
    }
    vii menorPossivel(qL, vi(qL, -1));
    while(qP--) solve(grid, pontos, menorPossivel);

    return 0; 
}
