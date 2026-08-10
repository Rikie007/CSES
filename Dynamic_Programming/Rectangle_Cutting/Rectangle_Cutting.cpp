/*
 * Problem Name: Rectangle_Cutting
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
void solve() {
    int A, B;
    cin >> A >> B;
 
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, 0));
 
    for(int a = 1; a <= A; a++) {
        for(int b = 1; b <= B; b++) {
 
            if(a == b) {
                dp[a][b] = 0;
                continue;
            }
 
            dp[a][b] = INT_MAX;
 
            // Cut horizontally
            for(int i = 1; i < a; i++) {
                dp[a][b] = min(dp[a][b],
                    1 + dp[i][b] + dp[a-i][b]
                );
            }
 
            // Cut vertically
            for(int i = 1; i < b; i++) {
                dp[a][b] = min(dp[a][b],
                    1 + dp[a][i] + dp[a][b-i]
                );
            }
        }
    }
 
    cout << dp[A][B] << '\n';
}
 
 
int main(){
 
    Code By Rikie
 
    
        solve();
        
    
    return 0;
}