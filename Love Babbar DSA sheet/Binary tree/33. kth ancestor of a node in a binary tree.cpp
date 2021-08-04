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


struct Node {
    ll data;
    Node *left,*right;
};

Node *newNode (ll data) {
    Node *current = new Node;
    current->data = data;
    current->left = current->right = NULL;
    return  current;
}

void inOrder(Node * root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

void preOrder(Node *root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

Node * deserialise(vector<ll> &arr,ll &curr) {
    if(arr[curr] == -1) {
        curr++;
        return NULL;
    }
    Node * current = newNode(arr[curr]);
    curr++;
    current->left = deserialise(arr,curr);
    current->right = deserialise(arr,curr);
    return current;
}

void kth_ancestor(Node *root,ll &k,ll &target,ll &ancestor,ll &target_k,ll &ans) {
    if(root == NULL) return;

    if(root->data == target) {
        target_k = k - ancestor;
    }
    k++ ;
    kth_ancestor(root->left,k,target,ancestor,target_k,ans);
    kth_ancestor(root->right,k,target,ancestor,target_k,ans);
    k--;
    if(k == target_k && ans == -1) {
        ans = root->data;
    }
    return;
}

void solve() {

    cinll(n);
    vector<ll> arr;
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr.pb(x);
    }
    ll curr = 0;
    Node *root = deserialise(arr,curr);
    inOrder(root);
    cout<<"\n";
    preOrder(root);
    cout<<"\n";

    ll k = 0;
    cinll(target);
    cinll(ancestor);
    ll target_k = -1;
    ll ans = -1;
    kth_ancestor(root,k,target,ancestor,target_k,ans);
    cout<<ans<<"\n";

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
