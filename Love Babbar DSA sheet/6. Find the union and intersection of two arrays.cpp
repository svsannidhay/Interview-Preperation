#include<iostream>
#include<vector>
#include<set>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define pb(x) push_back(x)

using namespace std;

// Using set

void unionSet(vector<ll> &arr1,vector<ll> &arr2) {
  set<ll> ans;
  for(ll i = 0;i < arr1.size(); i++) {
    ans.insert(arr1[i]);
  }
  for(ll i = 0;i < arr2.size(); i++) {
    ans.insert(arr2[i]);
  }
  cout<<ans.size()<<" ";
}

void intersectionSet(vector<ll> &arr1,vector<ll> &arr2) {
  set<ll> s1;
  for(ll i = 0;i < arr1.size(); i++) {
    s1.insert(arr1[i]);
  }
  set<ll> ans;
  for(ll i = 0;i < arr2.size(); i++) {
    ll size = s1.size();
    s1.insert(arr2[i]);
    if(s1.size() == size) {
      s1.erase(s1.find(arr2[i]));
      ans.insert(arr2[i]);
    }
  }
  cout<<ans.size()<<" ";
}



void solve() {
  cinll(n);cinll(m);
  vector<ll> arr1,arr2;
  for(ll i = 0;i < n;i++) {
    cinll(x);
    arr1.pb(x);
  } 
  for(ll i = 0;i < m; i++) {
    cinll(x);
    arr2.pb(x);
  }
  unionSet(arr1,arr2);
  intersectionSet(arr1,arr2);
  return;
}

int main () {
  solve();
  return 0;
}