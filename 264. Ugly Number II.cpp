An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690


code:
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n+1);
        ans[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i=2;i<=n;i++){
            ans[i] = min({ans[p2] * 2, ans[p3] * 3, ans[p5] * 5});
            if (ans[i] == ans[p2] * 2) p2++;
            if (ans[i] == ans[p3] * 3) p3++;
            if (ans[i] == ans[p5] * 5) p5++;
        }
        return ans[n];
    }
};
