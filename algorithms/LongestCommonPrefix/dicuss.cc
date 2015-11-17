class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
            
        int i = 0;
        for( ; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                //没有检测越界问题
                if(strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, i);
    }
};
