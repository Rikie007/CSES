/*
 * Problem Name: Projects
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-13
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
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0 ; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] ;
    }
 
    sort(arr.begin(), arr.end(), [](vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    });
 
    set<pair<int, ll>> st;
    st.insert({0,0LL});
    ll ans = 0;
    for(int i = 0 ; i < n;i++){
        auto t = st.lower_bound({arr[i][0], -1});
        t--;
        ans = max(ans, arr[i][2] + t->second);
        st.insert({arr[i][1],ans});
    }
    cout << ans;
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}