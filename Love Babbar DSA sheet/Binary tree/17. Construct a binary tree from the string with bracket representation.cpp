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

Node *newNode (ll data){
    Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preOrder(Node *root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

Node *root = NULL;

void solve_recurr(vector<string> &arr,ll data,ll left,ll right,Node * root) {
    if(right - left <= 2) return;
    root->data = data;
    ll l1 = left;
    stack<ll> st;
    bool first = true;
    while(left <= right) {
        if(arr[left] == "(" || arr[left] == ")") {
            if(st.empty() || arr[left] == "(") {
                st.push(1);
            } else {
                st.pop ();
            }

            if(st.size() == 0) {
                ll l = l1;
                ll r = left;
                l1 = left + 1;
                Node * l_c = newNode(stoi(arr[l+1]));
                if(first) root->left = l_c;
                else root->right = l_c;
                first = false;
                solve_recurr(arr,stoi(arr[l+1]),l + 2,r,l_c);
            }

        }
        left++;
    }
}

void solve() {
    cins(s);
    vector<string> parsed;
    ll start = 0;
    string curr = "";
    while(start < s.length()) {
        if(s[start] == '(' || s[start] == ')') {
            if(curr != "") parsed.push_back(curr);
            curr = "";
            if(s[start] == '(') curr = "(";
            else curr = ")";
            if(curr != "") parsed.push_back(curr);
            curr = "";
        } else {
            curr.pb(s[start]);
        }
        start++;
    }
    root = newNode(stoi(parsed[0]));
    solve_recurr(parsed,stoi(parsed[0]),1,parsed.size()-1,root);
    preOrder(root);
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
