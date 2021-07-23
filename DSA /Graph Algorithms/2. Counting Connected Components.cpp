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

void addEdge(vector< ll > adj[],ll u,ll v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
  return;
}

void dfs(vector< ll > adj[],vector< bool > &visited,vector< ll > &dist,ll current,ll dis) {
  if(!visited[current]) {
    visited[current] = true;
    dist[current] = dis;
    for(ll i=0;i<adj[current].size();i++) {
      dfs(adj,visited,dist,adj[current][i],dis + 1);
    }
  }
} 

vector<ll> sssp(vector<ll> adj[], ll n,ll source) {
  vector<ll> dist(n+1,-1);
  dist[source] = 0;
  vector<bool> visited(n+1,false);
  dfs(adj,visited,dist,source,0);
  return dist;
}

void solve() {
  cinll(n);
  vector< ll > adj[n+1];
  for(ll i = 0;i < n-1 ; i++) {
    cinll(u);cinll(v);
    addEdge(adj,u,v);
  }
  vector<ll> dist = sssp(adj,n,5);
  for(auto it:dist) cout<<it<<" ";
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
