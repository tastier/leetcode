class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        int max = 0;
        int len = 0;
        unordered_map<char, int> m;
        unordered_map<char, int>::iterator it;

        for(int i = 0; i < s.size(); ++i){
            it = m.find( s[i] );
            //found and the char is between start and i
            if( it != m.end() && it->second > start ) {
                start = it->second;
            }

            len = i - start;
            max = max > len ? max : len;
            m[ s[i] ] = i;
        }
        return max;
    }
};
