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

ll memo[1001][1001];
// Top - down 
ll solvememo(vector<ll> & arr,ll sum,ll n) {
    if(sum == 0) return memo[n][sum] = 1;
    if(n == 0) return memo[n][sum] = 0;
    if(memo[n][sum] != -1) return memo[n][sum];
    memo[n][sum] = solvememo(arr,sum,n-1);
    if(arr[n-1] <= sum) {
        memo[n][sum] += solvememo(arr,sum - arr[n-1],n-1);
    }   
    return memo[n][sum];
}
// Bottom up
ll solvedp(vector<ll> &arr, ll sum,ll n) {
    ll dp[1001][1001];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<=sum;i++) dp[0][sum] = 0;
    for(ll i=0;i<=n;i++) dp[i][0] = 1;

    for(ll i=1;i<=sum;i++) {
        for(ll j=1;j<=sum;j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        } 
    }
    return dp[n][sum];
}

void solve() {
    memset(memo,-1,sizeof(memo));
    cinll(n);cinll(sum);
    vector<ll> arr;
    for(ll i = 0;i < n; i++) {
        cinll(x);
        arr.pb(x);
    }
    cout<<solvememo(arr,sum,arr.size())<<" ";
    cout<<solvedp(arr,sum,arr.size())<<"\n";
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
