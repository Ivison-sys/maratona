#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    sort(a.begin(), a.end(), [](const string &x, const string &y){
        return x + y < y + x;
    });

    for (auto &s : a) cout << s;
    cout << '\n';

    return 0; 
}