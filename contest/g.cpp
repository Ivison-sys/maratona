// #include <bits/stdc++.h>
// #define nl << '\n'
// #define ll long long
// using namespace std; 
// using vi = vector<int>; using vll = vector<vector<long long>>;
// using vs = vector<string>; using vii = vector<vector<int>>;
// using vd = vector<double>; using vdd = vector<vector<double>>;
 
// void solve(){
//     int qP, limit; cin >> qP >> limit;

//     int time = 0, lastMin = 0;
//     priority_queue<int> pratosC;
//     vi t(qP), p(qP);
//     for(auto &x: t) cin >> x;
//     for(auto &x: p) cin >> x;

//     for(int i = 0; i < qP; i++){
//         if(time + t[i] - lastMin <= limit){
//             time += t[i] - lastMin;
//             lastMin = t[i];

//             if(time + p[i] <= limit){
//                 time += p[i];
//                 pratosC.push(p[i]);
//             } else if(!pratosC.empty() && pratosC.top() > p[i]){
//                 time = time - pratosC.top() - p[i];
//                 pratosC.pop(); pratosC.push(p[i]);
//             }
//         }else if(!pratosC.empty() && time + t[i] - lastMin - pratosC.top()  )
//     }

// }
 
// int main(){ 
//     ios::sync_with_stdio(false);
//     cin.tie(0); 
 
//     int tc; cin >> tc; while(tc--){
//         solve();
//     }
 
//     return 0; 
// }