Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
 
Code:
class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n+1, 0);

        ans[0] = 1;
        ans[1] = 1;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                ans[i] += ans[j-1] * ans[i-j];
            }
        }
        return ans[n];
    }
};
