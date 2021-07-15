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


string solve_dp(string a,string b) {
    ll n = a.length();
    ll m = b.length();
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<=n;i++) dp[i][0] = 0;
    for(ll i=0;i<=m;i++) dp[0][i] = 0;

    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    ll i = n;
    ll j = m;

    string lcs = "";
    string shortest_common_superseq = "";

    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            lcs.pb(a[i-1]);
            shortest_common_superseq.pb(a[i-1]);
            i--;
            j--;
        } else if(dp[i][j-1] > dp[i-1][j]) {
            shortest_common_superseq.pb(b[j-1]);
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            shortest_common_superseq.pb(a[i-1]);
            i--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    reverse(shortest_common_superseq.begin(),shortest_common_superseq.end());
    return shortest_common_superseq;
}

  
void solve() {
    cins(a);cins(b);
    cout<<solve_dp(a,b);
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
    for(ll i=1;i<=t;i++) {
        // cout<<solve()<<"\n";
        solve();
    }
  return 0;
}
