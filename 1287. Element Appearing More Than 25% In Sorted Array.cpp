Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105

Code:
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int maxi = n / 4;
        unordered_map<int, int> ans;

        for(int it : arr){
            ans[it]++;
            if(ans[it] > maxi){
                return it;
            }
        }
        return -1;
    }
};
