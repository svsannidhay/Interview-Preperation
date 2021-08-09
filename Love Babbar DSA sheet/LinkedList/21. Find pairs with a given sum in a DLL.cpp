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
    int data;
    Node *next,*prev;
};

Node * newNode (ll data) {
    Node * current = new Node;
    current->data = data;
    current->next = NULL;
    current->prev = NULL;
    return current;
}

void insertBeg(Node **head,ll data) {
    Node * current = newNode(data);
    if(*head == NULL) {
        *head = current;
    } else {
        current->next = *head;
        (*head)->prev = current;
        *head = current;
    }
    return;
}


void display(Node * current) {
    while(current != NULL) {
        cout<<current->data<<" ";
        if(current->next == NULL) break;
        current = current->next;
    }
    cout<<"\n";
    while(current != NULL) {
        cout<<current->data<<" ";
        current = current->prev;
    }
    cout<<"\n";
    return;
}

void findPairs(Node *head,ll x) {
    Node * left = head;
    Node * right = head;
    while(right->next != NULL) right = right->next;

    while(1) {
        ll currsum = left->data + right->data;
        if(currsum == x) {
            cout<<left->data<<" "<<right->data<<"\n";
            left = left->next;
            right = right->prev;
        } else {
            if(currsum < x) left = left->next;
            else {
                right = right->prev;
            }
        }
        if(left == right || right->next == left) break;
    }

}    

void solve() {
    Node *head = NULL;
    insertBeg(&head,3);
    insertBeg(&head,3);
    insertBeg(&head,2);
    insertBeg(&head,1);
    findPairs(head,3);
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
