#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>; using vii = vector<vector<int>>;

int qL, qC, inicio;

bool cicloEncontrado = false;
vi ciclo;

void caminhoCiclo(vi inicio, vi fim, vii &antecessor) {
    vii temp;
    temp.push_back(inicio);

    vi atual = fim;
    while (atual != inicio) {
        temp.push_back(atual);
        atual = antecessor[atual];
    }
    temp.push_back(inicio);

    reverse(temp.begin(), temp.end());
    ciclo = temp;
}

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

bool valid(int x, int y){
    return x >= 0 && x < qC && y >= 0 && y < qL;
}

pair<int, pair<int, int>> novaPosicao(char mov, int x, int y, vii &marcado, vii &antecessor){
    int i, ax, ay;
    marcado[y][x] = 1;
    if(mov == 'E') i = 0;
    else if(mov == 'N') i = 1; 
    else if(mov == 'S') i = 2; 
    else if(mov == 'W') i = 3;
    
    ax = x + dx[i]; ay = y + dy[i];
    if(!valid) return {0, {ax, ay}};
    if(marcado[ay][ax] == 1){
        cicloEncontrado = true;
        caminhoCiclo(u, v, antecessor);
        return;
    }

}

void rec(vs &grid, vii &antecessor, vii &marcado, int x, int y){
    marcado[x][y] = 1;


}

void busca(vs &grid){
    vii antecessor(qL, vi(qC, -1));
    vii marcado(qL, vi(qC, 0));
    
}

void solve(){
    vs grid(qL);
    for(auto &x: grid) cin >> x;

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
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    cin >> qL >> qC, inicio;
    while(qL != 0 && qC != 0 && inicio != 0){
        solve();
        cin >> qL >> qC, inicio;
    }
    
    return 0; 
}