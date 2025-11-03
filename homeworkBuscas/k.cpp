#include <bits/stdc++.h>
#define nl << '\n'
using namespace std;
#define ll long long 
using vi = vector<int>;

ll diff = LLONG_MAX;

void subConjuntos(vi &pesos, ll sum, int i, ll total){
    if(i == pesos.size()){
        diff = min(diff, abs(total - 2*sum));
        return;
    }
    subConjuntos(pesos, sum + pesos[i], i + 1, total);

    subConjuntos(pesos, sum, i + 1, total);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi pesos(n);
    ll total = 0;

    for(auto &x: pesos){
        cin >> x;
        total += x;
    }

    subConjuntos(pesos, 0, 0, total);
    cout << diff nl;

    return 0;
}
