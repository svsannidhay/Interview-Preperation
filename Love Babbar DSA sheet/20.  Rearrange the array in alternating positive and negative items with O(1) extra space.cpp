// METHOD 1
/*

  Lets make two pointers one which keeps track on next unused poistive integer and one 
  which keeps track on next unsed negative number 
  Now we can greedly move these pointers to the right to keep searching if some positive 
  number is left and greedly place it same goes for the negative numbers 

  Time Complexity : O(N)
  Space Complexity : O(1)

*/

#include<iostream>
#include<vector>

#define ll long long int 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)

using namespace std;

void solve() {
  cinll(n);
  vector<ll> arr;
  for(ll i = 0; i < n; i++) {
    cinll(x);
    arr.pb(x);
  }

  ll pos = 0;
  ll neg = 0;
  for(ll i = 0;i < n; i++) {
    if(i % 2 == 0) {
      // Find the postive number on right side if pos == n+1 which means no positive number 
      while(pos < n && arr[pos] < 0) {
        pos++;
      }
      if(pos != n) {
        swap(arr[pos],arr[i]);
        pos++;
      }
    } else {
      while (neg < n && arr[neg] > 0) {
        neg++;
      }
      if (neg != n) {
        swap(arr[neg], arr[i]);
        neg++;
      }
    }
  }

  for(ll i = 0; i < n; i++) {
    cout<<arr[i]<<" ";
  }

}

int main() {
  solve();
  return 0;
}