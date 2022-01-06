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
 
void dfs(vector< ll > adj[],vector<bool> &visit1,ll current ,ll &v,ll &dv,ll d) {
    visit1[current] = true; 
    if(d > dv) {
        v = current;
        dv = d;
    }
    for(auto i: adj[current]) {
        if(!visit1[i]) {
            dfs(adj,visit1,i,v,dv,d+1);
        }
    }
} 
 
void solve() {
    cinll(n);
    vector< ll > adj[n+1];
    for(ll i=0;i<n-1;i++) {
        cinll(a);cinll(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll v1 = -1;
    ll dv1 = 0;
    vector<bool> visit1(n+1,false);
    dfs(adj,visit1,1,v1,dv1,0);
    ll v2 = -1;
    ll dv2 = 0;
    vector<bool> visit2(n+1,false);
    dfs(adj,visit2,v1,v2,dv2,0);
    cout<<dv2;
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
