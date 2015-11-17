class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
            
        string longest;
        string tmp;
        int len = s.size();
        
        int ii = 0;
        while(s[ii] == s[ii+1]){
            if(ii == len-2)
                return s;
            ++ii;
        }
        //对于每一个i都判断一次回文数
        for(int i = 0; i < len; i++){
            //aa的形态
            if( (i + 1) < len && s[i] == s[i+1] ){
                int j = i - 1;
                int k = i + 2;
                while( j >= 0 && k < len && s[j] == s[k]){
                    --j;
                    ++k;
                }
                if( k-j-1 > longest.size() )
                    longest = s.substr(j+1, k-j-1);
                if(k == len)
                    break;
            }
            //aba的形态
            if( (i + 2) < len && s[i] == s[i+2] ){
                int j = i - 1;
                int k = i + 3;
                while(j >= 0 && k < len && s[j] == s[k]){
                    --j;
                    ++k;
                }
                if( k-j-1 > longest.size() )
                    longest = s.substr(j+1, k-j-1);
                if(k == len)
                    break;
            }
        }
        if(longest.size() == 0)
            return s.substr(0, 1);
        return longest;
    }
};
