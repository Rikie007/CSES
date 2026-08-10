/*
 * Problem Name: Money_Sums
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-10
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    int total = 0;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        total += x;
    }
    vector<vector<bool>> dp(n+1, vector<bool>(total + 1, false));
 
    dp[0][0] = true;
    // set<int> st;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= total; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i-1] >= 0)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            // if(dp[i][j]) st.insert(j);
        }
    }
 
    vector<int> ans ;
 
    for(int i = 1; i <= total; i++){
        if(dp[n][i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << " ";
    }cout << endl;
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}