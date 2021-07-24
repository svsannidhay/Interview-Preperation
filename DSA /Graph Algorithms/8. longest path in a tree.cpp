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

void dfs(vector< ll > adj[],vector<bool> &vis1,ll current,
    ll curr_d,ll &deepest_n,ll &max_d_it1) {
    if(!vis1[current]) {
        vis1[current] = true;
        if(curr_d > max_d_it1) {
            max_d_it1 = curr_d;
            deepest_n = current;
        }
        for(ll i=0;i<adj[current].size();i++) {
            if(!vis1[adj[current][i]]) {
                dfs(adj,vis1,adj[current][i],curr_d + 1,deepest_n,max_d_it1);
            }
        }
    }
}

void dfs_deep(vector< ll > adj[],vector<bool> &vis2,ll current,ll depth,ll &max_d_it2) {
    if(!vis2[current]) {
        vis2[current] = true;
        if(depth > max_d_it2) {
            max_d_it2 = depth;
        }
        for(ll i=0;i<adj[current].size();i++) {
            if(!vis2[adj[current][i]]) {
                dfs_deep(adj,vis2,adj[current][i],depth + 1,max_d_it2);
            }
        }

    }
}


void solve() {
    cinll(n);
    vector< ll > adj[n+1];
    for(ll i=0;i<n-1;i++) {
        cinll(u);cinll(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<bool> vis1(n+1,false);
    vector<bool> vis2(n+1,false);

    ll deepest_n = -1;
    ll max_d_it1 = -1;
    ll max_d_it2 = -1;

    dfs(adj,vis1,1,0,deepest_n,max_d_it1);

    dfs_deep(adj,vis2,deepest_n,0,max_d_it2);

    cout<<max_d_it2;

    return;
}

int main() {
    fio;
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
// ///////////////////////////////////////////
    // cinll(t);
    // for(ll i=0;i<t;i++) {
        solve();
    // }
  return 0;
}
