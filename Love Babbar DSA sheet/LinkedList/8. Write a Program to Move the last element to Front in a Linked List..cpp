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

struct  Node {
    int data;
    Node *next;
};

Node * newNode (ll data) {
    Node * current = new Node;
    current->data = data;
    current->next = NULL;
    return current;
}

void insert_beg(Node ** head,ll x){
    Node * current = newNode(x);
    if(*head == NULL) { 
        *head = current;
    } else {
        current->next = *head;
        *head = current;
    }
    return;
}

void display(Node *head) {
    Node * traverse = head;
    while(traverse != NULL) {
        cout<<traverse->data<<" "; 
        traverse = traverse->next;
    }
} 

void move_last_to_beg(Node **head) {
    Node *last;
    Node *slast;

    Node * traverse = *head;
    while(traverse != NULL) {
        if(traverse->next != NULL && traverse->next->next == NULL) {
            slast = traverse;
        }
        if(traverse->next == NULL) {
            last = traverse;
        }
        traverse = traverse->next;
    }
    slast->next = NULL;
    last->next = *head;
    *head = last;

    return;
}

void solve() {
    Node *head = NULL;
    insert_beg(&head,10);
    insert_beg(&head,20);
    insert_beg(&head,1);
    insert_beg(&head,2);
    move_last_to_beg(&head);
    display(head);

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
