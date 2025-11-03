#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int n; cin >> n;
    int vidaA = 0, num, c=0;

    while(n--){
        cin >> num;
        vidaA += num;
        if(vidaA < 0){
            c += 0 - vidaA; 
            vidaA = 0;
        }
    }
    cout << c nl;
    return 0; 
}