You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

 

Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 10^4


Code:
class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int sum = 0;

            while(num > 0){
                int rem = num % 10;
                sum += rem;
                num /= 10;
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};
