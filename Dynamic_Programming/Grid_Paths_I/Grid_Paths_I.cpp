/*
 * Problem Name: Grid_Paths_I
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
ll t[1001][1001];
int N, M = 1e9 + 7;
ll sol(int i, int j, vector<vector<char>> &grid){
    if(i < 0 || j < 0 || i >= N|| j >= N) return 0;
    if(grid[i][j] == '*') return 0;
    if(i == N-1 &&  j == N-1){
        return 1;
    }
    if(t[i][j] != -1) return t[i][j];
    return t[i][j] = (sol(i+1,j,grid) + sol(i, j+1, grid)) % M;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n));
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            char ch; cin >> ch;
            grid[i][j] = ch;
        }
    }
    N = n;
 
    memset(t, -1, sizeof(t));
    cout << sol(0,0,grid);
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}