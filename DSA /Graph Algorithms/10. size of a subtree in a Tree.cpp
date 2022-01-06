//////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <climits>
#include <set>
#include <cstring>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <stdlib.h>
#include <chrono>
 
///////////////////////////////////////////////////////////////////////////////////////////////////
#define fio  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll  long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin >> x;
#define cini(x) int x;cin >> x;
#define cins(x) string x;cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 1e17
#define MIN -9223372036854775800
#define MOD 1000000007
#define f first
#define s second
#define LOG 32
#define MAX_S 100001
const ll maxN = 17;
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;

ll sizeSubTree(vector< ll > adj[], vector< ll > &dp,ll current) {
    dp[current] = 1;
    for(auto i:adj[current]) {
        if(dp[i] == -1)   dp[current] += sizeSubTree(adj,dp,i);
    }
    return dp[current];
}

void solve() {
    cinll(n);
    vector< ll > adj[n+1];
    for(ll i=0;i<n-1;i++) {
        cinll(a);cinll(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector< ll > dp;
    for(ll i = 0 ; i <= n+1; i++) {
        dp.pb(-1);
    } 
    sizeSubTree(adj,dp,1);
    for(ll i=1;i<=n;i++) {
        cout<<dp[i]<<" ";
    }
    return;
}

int main() {
    fio;
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
/////////////////////////////////////////////
    // cinll(t);
    // for(ll i = 0;i < t; i++) {
        solve();
    // }
  return 0;
}
