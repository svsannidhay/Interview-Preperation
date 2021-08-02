/*

  Time Complexity : O(N)
  Space Complexity : O(N)

  used custom serialization.


  FOR BINARY TREE 
  Use DFS appraoch 

  int areMirror(Node* a, Node* b)
{
if (a == NULL && b == NULL)
  return true;
if (a == NULL || b == NULL)
  return false;
return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

  TC : O(N)
  MC : O(1)

*/
class Solution {
  public:
  
    void addEdge(vector<int> adj[],int u,int v) {
        adj[u].push_back(v);
        return;
    }
  
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int> adj1[n+1];
        vector<int> adj2[n+1];
        for(int i=0;i < 2*e;i+=2) {
            addEdge(adj1,A[i],A[i+1]);
            addEdge(adj2,B[i],B[i+1]);
        }
        // Create mirror
        for(int i = 1; i <= n; i++) {
            reverse(adj1[i].begin(),adj1[i].end());
        }
        bool ok = true;
        for(int i=1;i<=n;i++) {
            if(adj1[i] != adj2[i]) ok = false;
        }
        return ok;
    }
};