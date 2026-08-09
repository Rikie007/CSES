/*
 * Problem Name: Edit_Distance
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-09
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
string s1, s2;
int m,n;
int t[5001][5001];
int sol(int i, int j){
    if(i >= m){
        return (n-j) >= 0 ? n-j : 0;
    }
    if(j >= n){
        return (m-i) >= 0 ? m-i : 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int ans = 0;
    if(s1[i] == s2[j]){
        ans = sol(i+1,j+1);
    }
    else{
        ans = 1 + min({sol(i+1,j), sol(i+1,j+1), sol(i, j+1)});
    }
    return t[i][j] = ans;
}
void solve(){
    cin >> s1 >> s2;
    m = s1.size();
    n = s2.size();
    memset(t,-1,sizeof(t));
    cout << sol(0,0);
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}