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
    adj[u].pb(v);
    adj[v].pb(u);
    return;
}

void dfs(vector< ll > adj[],vector<bool> &visited,ll current,ll &count) {
    if(!visited[current]) {
        count++;
        visited[current] = true;
        for(ll i=0;i<adj[current].size();i++) {
            if(!visited[adj[current][i]]) {
                dfs(adj,visited,adj[current][i],count);
            } 
        }
    }
}

void solve() {
    cinll(n);cinll(m);
    vector< ll > adj[n+1];
    for(ll i = 1;i <= m; i++) {
        cinll(u);cinll(v);
        addEdge(adj,u,v);
    }

    vector<bool> visited(n+5,false);
    ll count = 0;
    ll leaders = 1;
    ll cnt_cc = 0;
    for(ll i = 1;i <= n; i++) {
        if(!visited[i]) {
            cnt_cc++;
            dfs(adj,visited,i,count);
            leaders = (leaders * count) % MOD;
            count = 0;
        }
    }
    cout<<cnt_cc<<" "<<leaders<<"\n";
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
    cinll(t);
    for(ll i=0;i<t;i++) {
        solve();
    }
  return 0;
}
