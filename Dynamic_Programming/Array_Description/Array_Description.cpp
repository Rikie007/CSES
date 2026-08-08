/*
 * Problem Name: Array_Description
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-08
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
// int N , M;
int MOD = 1e9 + 7;
// ll t[100001][101];
// ll sol(int idx, int last, vector<int> &arr){
//     if(idx == arr.size()){
//         return 1;
//     }
//     if(last != -1 && arr[idx] != 0 && abs(last - arr[idx]) > 1){
//         return 0;
//     }
 
//     if(last != -1 && t[idx][last] != -1) return t[idx][last];
//     ll ans = 0LL;
//     if(arr[idx] == 0){
//         for(int i = 1; i <= M; i++){
//             if(last == -1 || abs(i - last) <= 1)
//                 ans = (ans + sol(idx+1, i, arr)) ;
 
//             if(ans >= MOD) ans -= MOD;
//         }
//     }
//     else{
//         ans = (ans + sol(idx+1, arr[idx], arr)) ;
//         if(ans >= MOD) ans -= MOD;
//     }
//     return t[idx][last] = ans;
// }
void solve(){
    int n, m;
    cin >> n >> m;
    // N = n; M = m;
    vector<int> arr;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // memset(t, -1, sizeof(t));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int j = 1; j <= m;j++){
        dp[n][j] = 1;
    }
 
    for(int i = n-1 ; i >= 0; i--){
        if(arr[i] != 0){
            int val = arr[i];
 
            for(int last = 1; last <= m; last++) {
 
                if(abs(last - val) <= 1) {
                    dp[i][last] = dp[i + 1][val];
                }
            }
        }
        else{
            for(int j = 1 ; j <= m ; j++){
                if(j-1 >= 1){
                    dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
                }
                if(j + 1 <= m){
                    dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % MOD; 
                }
                dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
            }
        }
    }
    ll ans = 0LL;
    if(arr[0] == 0){
        for(int i = 1 ; i <= m; i++){
            ans = (ans + dp[1][i]) % MOD;
        }
    }else{
        ans = dp[1][arr[0]];
    }
    cout << ans;
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}   