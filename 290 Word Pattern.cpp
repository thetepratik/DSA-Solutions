Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

  code:
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        string ss = "";

        for(char c:s){
            if(c == ' '){
                word.push_back(ss);
                ss = "";
            }else{
                ss += c;
            }
        }

        word.push_back(ss);
        if(pattern.size() != word.size()) return false;

        unordered_map<string, char> m2;
        unordered_map<char, string> m1;
        for(int i=0;i<pattern.size();i++){
            char p = pattern[i];
            string w = word[i];

            if(m1.count(p)){
                if(m1[p] != w) return false;
            }else{
                if(m2.count(w)) return false;
                m1[p] = w;
                m2[w] = p; 
            }
        }
        return true;
    }
};
