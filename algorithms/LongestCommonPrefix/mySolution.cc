class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        string pre = findComm(strs[0], strs[1]);
        for(int i = 2; i < strs.size(); i++){
            if(pre.size() == 0)
                return "";
            pre = findComm(pre, strs[i]);
        }
        return pre;
    }
private:
    string findComm(string& s1, string& s2)
    {
        string ret;
        int len = s1.size() > s2.size() ? s2.size() : s1.size(); 
        for(int i = 0; i < len; i++){
            if(s1[i] == s2[i])
                ret.push_back(s1[i]);
            else
                break;
        }
        return ret;
    }
};
