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
#define LOG 14
#define MAX_S 100001
const ll maxN = 17;
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;


/////////////////////////////// Lowest Common Ancestor (Binary lifing) ///////////////////////////
#define MAX_N 100001
#define LOG 14

// Sparse table

ll LCA[MAX_N][LOG+1];

void dfs(ll node,ll parent,vector<ll> adj[],ll dep,vector<ll> &depth) {
    depth[node] = dep;
    LCA[node][0] = parent;
    for(ll child: adj[node]) {
        if(child != parent) {   // prevents dfs to call back to parent without using visited array
            dfs(child,node,adj,dep + 1,depth);
        }
    }
} 

void sparse_init(vector<ll> adj[],vector<ll> &depth) {
    dfs(1,-1,adj,0,depth);
    for(ll j = 1; j <= LOG; j++) {
        for(ll i = 1;i <= MAX_N; i++) {
            if(LCA[i][j-1] != -1) {
                LCA[i][j] = LCA[LCA[i][j-1]][j-1];
            }
        }
    } 
}

ll lca(ll a,ll b,vector<ll> &depth) {
    if(depth[a] > depth[b]) swap(a,b);
    ll d = depth[b] - depth[a];

    for(ll j = LOG;j >= 0; j--) {
        if(d & (1 << j)) {
            b = LCA[b][j];
        }
    } 
    if(a == b) return a;
    for(ll j = LOG; j >= 0; j--) {
        if(LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j])){
              a = LCA[a][j] , b = LCA[b][j];
        }
    }
    return LCA[a][0];
}

ll get_dist(ll a,ll b,vector<ll> &depth) {
    ll lowest_common_ansector = lca(a,b,depth);
    return depth[a] + depth[b] - 2 * depth[lowest_common_ansector];
} 

//////////////////////////////////////////////////////////////////////////////////////////////////
void solve() {
    cinll(n);cinll(q);
    memset(LCA,-1,sizeof(LCA));
    vector<ll> adj[MAX_N];
    vector<ll> depth(MAX_N,0);
    for(ll i=1;i<n;i++) {
        cinll(a);cinll(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    sparse_init(adj,depth);

    for(ll i=0;i<q;i++) {
        cinll(a);cinll(b);
        cout<<get_dist(a,b,depth)<<"\n";
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
// ///////////////////////////////////////////


    // cinll(t);
    // for(ll i=1;i<=t;i++) {
        // cout<<solve()<<"\n";
        solve();
    // }
  return 0;
}
