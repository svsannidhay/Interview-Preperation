// Method 1 
/*
  Just count no of 0's,1's and 2's 
  then print them in order
*/
class Solution{      
  public:
    void sort012(int a[], int n)
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0;i < n; i++) {
            if(a[i] == 0) count0++;
            else if(a[i] == 1) count1++;
            else count2++;
        }
        int index = 0;
        while(count0 > 0) {
            a[index] = 0;
            count0--;
            index++;
        }
        while(count1 > 0) {
            a[index] = 1;
            count1--;
            index++;
        }
        while(count2 > 0) {
            a[index] = 2;
            index++;
            count2--;
        }
    }
};    
// METHOD 2
/*
Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
Traverse the array from start to end and mid is less than high. (Loop counter is i)
If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
If the element is 1 then update mid = mid + 1
If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the output array.

*/
class Solution {
public:
  void sort012(int a[], int n){
    int left = 0;
    int mid = 0;
    int right = n - 1;

    while (mid <= right)
    {
      if (a[mid] == 0)
      {
        swap(a[left], a[mid]);
        left++;
        mid++;
      }
      else if (a[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(a[mid], a[right]);
        right--;
      }
    }
  }
};