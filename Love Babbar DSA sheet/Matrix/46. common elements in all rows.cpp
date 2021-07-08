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
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;



void solve() {
    cinll(n);cinll(m);
    ll arr[n+1][m+1];

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    unordered_map<ll,ll> ans;
    for(ll i = 0;i < n;i++) {
        unordered_map<ll,ll> curr;
        for(ll j = 0;j < m; j++) {
            curr[arr[i][j]] = 1;
        }

        for(auto it = curr.begin();it!=curr.end();it++) {
            ans[it->first] += it->second;
        }

    }

    for(auto it = ans.begin();it!=ans.end();it++) {
        if(it->second == m) cout<<it->first<<" ";
    }

    return;

}    

int main() {
    fio;
    // cinll(t);
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
// ///////////////////////////////////////////
    // cout<<LCM(40);
    cinll(t);
    for(ll i=1;i<=t;i++) {
        // cout<<solve()<<"\n";
        solve();
    }
  return 0;
}
