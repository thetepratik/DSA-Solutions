Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9

Code:
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int duplicate = 0;
        int last = n - 1;

        for(int i=0;i<=last - duplicate;i++){
            if(arr[i] == 0){
                if(i == last - duplicate){
                    arr[last] = 0;
                    last -= 1;
                    break;
                }
                duplicate++;
            }
        }


        int current = last - duplicate;
        for(int i=current; i>=0;i--){
            if(arr[i] == 0){
                arr[i + duplicate] = 0;
                duplicate--;
                arr[i + duplicate] = 0;
            }else{
                arr[i + duplicate] = arr[i];
            }
        }
        // return arr;
    }
};
