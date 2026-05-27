
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.

 

Constraints:

1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.


Code:
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int count = 0;
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for(char ch : word){
            if(islower(ch)){
                lower[ch - 'a'] = true;
            }else if(isupper(ch)){
                upper[ch - 'A'] = true;
            }
        }

        for(int i=0;i<26;i++){
            if(lower[i] && upper[i]){
                count++;
            }
        }
        return count;
    }
};
