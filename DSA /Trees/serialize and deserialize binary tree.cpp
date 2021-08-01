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

Node * newNode(ll data) {
    Node * current = new Node;
    current->data = data;
    current->left = current->right = NULL;
    return current;
}

void serialize(Node * root,vector<ll> &serial) {
    if(root == NULL) {
        serial.push_back(-1);
        return;
    }
    serial.push_back(root->data);
    serialize(root->left,serial);
    serialize(root->right,serial);
    return;
}


Node * deserialize(vector<ll> &arr,ll &curr) {
    if(arr[curr] == -1) {
        curr++;
        return NULL;
    }
    Node *current  = newNode(arr[curr]);
    curr++;
    current->left = deserialize(arr,curr);
    current->right = deserialize(arr,curr);
    return current;
}

void inorder(Node *root) {
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void preorder(Node *root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

/*
    Sample 
    13
    1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1 

    Output : 
    4 2 5 1 3 6 
    1 2 4 5 3 6 
    1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1 

*/

void solve() {
    cinll(n);
    vector< ll > arr;
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr.pb(x);
    }
    ll curr = 0;
    Node * root = deserialize(arr,curr);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    vector<ll> serial;
    serialize(root,serial);
    for(auto i:serial) cout<<i<<" ";

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
