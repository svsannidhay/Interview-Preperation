/*

  Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 
  1 to low (the range containing 0), 
  low to mid (the range containing 1),
  mid to high (the range containing unknown elements) and 
  high to N (the range containing 2).
  Traverse the array from start to end and mid is less than high. (Loop counter is i)
  If the element is less than a then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
  If the element is between a and b then update mid = mid + 1
  If the element is greater than b then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed

  Time Complexity : O(N)
  Space Complexity : O(1)

*/

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int left = 0;
        int mid = 0;
        int right = arr.size()-1;
        while(mid <= right) {
            if(arr[mid] < a) {
                swap(arr[mid],arr[left]);
                left++;
                mid++;
            } else if(arr[mid] >= a && arr[mid] <= b) {
                mid++;
            } else {
                swap(arr[mid],arr[right]);
                right--;
            }
        }
    }
};