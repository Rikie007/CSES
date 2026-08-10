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
    ll sol(int i, int j){
        if(i > j){
            return 0;
        }
        if(i >= n || j < 0) return 0;
        if(t[i][j] != -1){
            return t[i][j];
        }
        ll ans = 0;
        
        ans = max({arr[i] + min(sol(i+2,j), sol(i+1,j-1)), arr[j] + min(sol(i+1,j-1), sol(i,j-2))});
 
        return t[i][j] = ans;
    }
 
    void solve(){
        cin >> n;
        for(int i = 0 ; i < n; i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        memset(t, -1LL , sizeof(t));
        cout << sol(0,n-1);
    }
 
    int main(){
 
        Code By Rikie
 
            solve();
 
        return 0;
    }