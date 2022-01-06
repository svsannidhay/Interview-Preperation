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

void addEdge(vector< ll > adj[],ll a,ll b) {
    adj[a].pb(b);
    adj[b].pb(a);
    return;
}

vector< ll > bfs(vector< ll > adj[],ll n,ll source) {
    queue< ll > q;
    q.push(source);
    vector< bool > visited(n+1,false);
    vector< ll > distance(n+1,0);
    distance[source] = 0;
    visited[source] = true;
    while(!q.empty()) {
        ll current = q.front();
        q.pop();
        for(auto i:adj[current]) {
            if(!visited[i]) {
                distance[i] = distance[current] + 1;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return distance;
}

void solve() {
    cinll(n);cinll(m);
    vector< ll > adj[n+1];
    for(ll i=0;i<m;i++) {
        cinll(a);cinll(b);
        addEdge(adj,a,b);
    }
    vector< ll > dist = bfs(adj,n,1);
    cout<<dist[n]<<"\n";
}

int main() {
    fio;
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
/////////////////////////////////////////////
    cinll(t);
    for(ll i = 0;i < t; i++) {
        solve();
    }
  return 0;
}
