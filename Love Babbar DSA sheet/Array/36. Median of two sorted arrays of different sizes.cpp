/*

  METHOD 1 : Brute force 
    MErge sort in O(N) time and O(1) space

  METHOD 2 : Binary search for the optimal partition points 

    Ex .  3 5 | 7 9 11       bianry search for this partition point.
          1 2 4 | 8 10 
          Partition point in second array is based upon the fact that exactly total / 2
          elements are smaller than median.
          median = 5 + 7 / 2

  Handle edge cases too (odd even sizes etc)

  Time complexity O(log(n))

  Which can be reduced to O(log(min(n,m))) by choosing the smaller array to perform 
  binary search over.

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() == 0) {
            if(nums1.size() % 2 == 0) {
                return (double)(nums1[nums1.size()/2] + nums1[nums1.size()/2-1]) / (double) 2;
            } else {
                return nums1[nums1.size()/2];
            }
        }
        if(nums1.size() == 0) {
            if(nums2.size() % 2 == 0) {
                return (double)(nums2[nums2.size()/2] + nums2[nums2.size()/2-1]) / (double) 2;
            } else {
                return nums2[nums2.size()/2];
            }
        }
        int half = (nums1.size() + nums2.size()) / 2;
        int left = 0;
        int right = nums1.size();
        double ans;
        while(left <= right) {
            int mid = (left + right) / 2;
            int p1 = mid;
            int p2 = half - mid;
            cout<<mid<<" "<<p1<<" "<<p2<<"\n";
            if(p2 < 0) {
              right = mid - 1;  
            } else if(p1 == 0) {
                if(nums2[p2-1] > nums1[p1]) {
                    left = mid + 1;
                } else {
                    if( (nums1.size() + nums2.size()) % 2 == 0) {
                        ans = (double)(nums1[p1] + nums2[p2-1]) / (double) 2;
                    } else {
                        if(p2 == nums2.size()) ans = nums1[p1];
                        else ans = min(nums2[p2],nums1[p1]);
                    }   
                    break;
                }
            } else if(p2 == 0) {
                if(nums1[p1-1] > nums2[p2]) {
                    right = mid - 1;  
                } else {
                    if( (nums1.size() + nums2.size()) % 2 == 0) {
                        ans = (double)(nums1[p1-1] + nums2[p2]) / (double) 2;
                    } else {
                       if(p1 == nums1.size()) ans = nums2[p2];
                       else ans = min(nums1[p1],nums2[p2]);
                    }
                    break;
                }
            } else if(nums1[p1-1] <= nums2[p2] && nums2[p2-1] <= nums1[p1]) {
                if( (nums1.size() + nums2.size()) % 2 == 0) {
                    ans = (double)(max(nums1[p1-1],nums2[p2-1]) + min(nums1[p1],nums2[p2])) / (double) 2;
                } else {
                    ans = min(nums1[p1],nums2[p2]);
                }
                break;
            } else if(nums1[p1-1] > nums2[p2]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        return ans;
    }
};
