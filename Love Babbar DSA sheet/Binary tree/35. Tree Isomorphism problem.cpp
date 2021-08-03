/*

  Time Complexity : O(N + M)
  Space Complexity : O(1)

*/
class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
    
        if(root1->data != root2->data) return false;
    
        bool same_iso = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
        bool cross_iso = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
        return same_iso || cross_iso;
    
    }
};
