#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
 
int qC, qL;

const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

bool valid(int x, int y){
    return x >= 0 && x < qL && y >= 0 && y < qC;
}
int oc = 0;
void verificarD(vs &grid, int x, int y, int i){
    int ax = x + dx[i], ay = y + dy[i];
    if(valid(ax, ay)){
        if(grid[ax][ay] == 'A' || grid[ax][ay] == 'a'){
            oc++;
        }
    }
}

void rec(vs &grid, int x, int y){
    if(grid[x][y] == 'U' || grid[x][y] == 'u'){
        for(int i = 0; i < 8; i++){
            int ax = x + dx[i], ay = y + dy[i];
            if(valid(ax, ay)){
                if(grid[ax][ay] == 'V' || grid[ax][ay] == 'v'){
                    verificarD(grid, ax, ay, i);
                }
            }
        }
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin >> qC >> qL;
    vs grid(qL);

    for(auto &x: grid) cin >> x;
    for(int i = 0; i < qL; i++){
        for(int w = 0; w < qC; w++){
            rec(grid, i, w);
        }
    }
    cout << oc nl;
    return 0; 
}