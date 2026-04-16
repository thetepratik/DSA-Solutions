You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.

 

Example 1:

Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

Output: [2,-1,3]

Explanation:

Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
Example 2:

Input: nums = [1,2,3,4], queries = [0,1,2,3]

Output: [-1,-1,-1,-1]

Explanation:

Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.

 

Constraints:

1 <= queries.length <= nums.length <= 105
1 <= nums[i] <= 106
0 <= queries[i] < nums.length
 
code:
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            ans[nums[i]].push_back(i);
        }

        vector<int> mindis(n, INT_MAX);
        for(auto& pair : ans){
            auto& arr = pair.second;
            int m = arr.size();
            if(m == 1){
                mindis[arr[0]] = -1;
                continue;
            }
            for(int i=0;i<m;i++){
                int prev = arr[(i-1+m)%m];
                int next = arr[(i+1)%m];
                int curr = arr[i];

                int distprev = min(abs(curr - prev), n-abs(curr - prev));
                int distnext = min(abs(curr - next), n-abs(curr - next));

                mindis[curr] = min(distprev, distnext);
            }
        }
        vector<int> result;
        for(int query : queries){
            result.push_back(mindis[query]);
        }
        return result;
    }
};
