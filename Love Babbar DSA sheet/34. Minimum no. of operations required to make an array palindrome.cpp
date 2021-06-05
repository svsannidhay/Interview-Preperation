/*

  METHOD 
  USE two pointers i = 0;
  and j = n-1;

  and greedly find the answer

*/

#include<iostream>
#include<vector>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)


using namespace std;

int solve() {
  cinll(n);
  vector<ll> arr;
  for(ll i = 0;i < n;i++) {
    cinll(x);
    arr.push_back(x);
  }  
  int left = 0;
  int right = n-1;
  int val_l = arr[left];
  int val_r = arr[right];
  int ans = 0;
  while(left < right) {
    if(val_l == val_r) {
      left++;
      right--;
      val_l = arr[left];
      val_r = arr[right];
    }
    if(val_l  < val_r) {
      left++;
      val_l += arr[left];
      ans++;
    } else {
      right--;
      val_r += arr[right];
      ans++;
    }
  }
  return ans;
}

int main() {
  
  cout<<solve();

  return 0;
}