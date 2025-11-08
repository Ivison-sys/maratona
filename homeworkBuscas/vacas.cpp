#include <bits/stdc++.h>
#define nl << '\n'
#define ll long long
using namespace std; 
using vi = vector<int>; using vll = vector<long long>;
 
bool f(vll &p, int d, int c){
    int pos = p[0]; c--;
    for(int i = 1; i < p.size() && c > 0; i++){
        if(p[i] - pos >= d){
            c--;
            pos = p[i];
        }
    }
    if(!c) return true;
    else return false;
}

void solve(){
    int n, c; cin >> n >> c;
    vll p(n);

    for(auto &x: p) cin >> x;

    if(c == n){
        cout << 1 nl; return;
    } else if(c > n){
        cout << 0 nl; return;
    } else{
        sort(p.begin(), p.end());
        ll l = 1, r = *(--p.end()) + 10, resp = 0;
        ll mid;
        while(l <= r){
            mid = (l+r)/2;
            if(f(p, mid, c)){
                resp = mid;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        cout << resp nl; return;
    }

    

}
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
 
    int tc; cin >> tc; while(tc--){
        solve();
    }
 
    return 0; 
}