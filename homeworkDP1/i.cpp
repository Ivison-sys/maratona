#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>;

int maxi= 1, inicio = 1;

void maiorSeq(int n, int ant, int l, vector<pair<int, int>> &numberes, vi &dp, vi &antecessor){
    
    if(n < 0 || ant < 0 || n >= l || ant >= l) return;
    if(numberes[n].first + 1 == numberes[ant].first && numberes[n].second < numberes[ant].second){
        dp[n] = 1 + dp[ant];
        antecessor[numberes[n].second] = numberes[ant].second;
        if(dp[n] > maxi){
            maxi = dp[n];
            inicio = numberes[n].second;
        }
    }
    else if(numberes[n].first == numberes[ant].first){
        maiorSeq(n, ant+1, l, numberes, dp, antecessor);
    }else if(numberes[n].first + 1 == numberes[ant].first){
        maiorSeq(n, ant+1, l, numberes, dp, antecessor);
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int q; cin >> q;

    vector<pair<int, int>> numbers(q);
    vi dp = vi(q, 1);
    vi antecessor(q,-1);
    for(int i = 0; i < q; i++){
        cin >> numbers[i].first;
        numbers[i].second = i+1;
    }

    sort(numbers.begin(), numbers.end());
    
    for(int i = q - 1; i >= 1; i--){
        maiorSeq(i+1, i, q, numbers, dp, antecessor);
    }

    cout << maxi nl;
    for(int i = 0; i < maxi; i++){
        cout << inicio << " ";
        inicio = antecessor[inicio];
    }
    cout nl;
    
    return 0; 
}