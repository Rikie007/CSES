/*
 * Problem Name: Removal_Game
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
 
int n;
vector<int> arr;
ll t[5001][5001];
 
void solve() {
    cin >> n;
 
    arr.resize(n);
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    // Base case:
    // Empty interval => 0
    for (int i = 0; i < n; i++) {
        t[i][i] = arr[i];
    }
 
    // length = size of current interval
    for (int len = 2; len <= n; len++) {
 
        for (int i = 0; i + len - 1 < n; i++) {
 
            int j = i + len - 1;
 
            ll left = arr[i] +
                      min(
                          (i + 2 <= j ? t[i + 2][j] : 0),
                          (i + 1 <= j - 1 ? t[i + 1][j - 1] : 0)
                      );
 
            ll right = arr[j] +
                       min(
                           (i + 1 <= j - 1 ? t[i + 1][j - 1] : 0),
                           (i <= j - 2 ? t[i][j - 2] : 0)
                       );
 
            t[i][j] = max(left, right);
        }
    }
 
    cout << t[0][n - 1] << '\n';
}
 
int main() {
 
    Code
    By
    Rikie
 
    solve();
 
    return 0;
}