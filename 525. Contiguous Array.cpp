Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

code:
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ans;
        ans[0] = -1;
        int sum = 0;
        int maxsum = 0;

        for(int i=0;i<nums.size();i++){
            sum += (nums[i] == 0)?-1:1;

            if(ans.find(sum) != ans.end()){
                maxsum = max(maxsum, i - ans[sum]);
            }else{
                ans[sum] = i;
            }
        }
        return maxsum;
    }
};
