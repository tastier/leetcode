// like count
class Solution {
public:
    vector<string> letterCombinations(string dig) {
        vector<string> ret;
        if(dig.size() == 0)
            return ret;

        int nums = 1;
        int size = dig.size();
        // int v[dig.size()]; // dig对应的十进制数字：2,3
        // int in[dig.size()]; // 每个数字对应字符串位置的索引
        // memset(in, 0, 4 * dig.size());
        vector<int> v (size, 0);
        vector<int> in (size, 0);
        vector<string> vec = { {""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
        
        for(int i = 0; i < size; i++) {
            if(dig[i] == '0' || dig[i] == '1')
                return ret;
            v[i] = dig[i] - 48;
            nums *= vec[ v[i] ].size();
        }
        while(nums--){
            string tmp;
            for(int i = 0; i < size; i++){
                if(in[i] == vec[v[i]].size()){
                    ++in[i+1];
                    in[i] = 0;
                }
                tmp += (vec[v[i]][in[i]]);
            }
            ++in[0];
            ret.push_back(tmp);
        }
        return ret;
    }
};

//DFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() == 0)
            return ret;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int depth = 0;
        string path;
        dfs(digits, map, ret, path, depth);
        return ret;
    }
private:
    // 变量p记录dfs走过的路径，dep记录当前位置的深度
    // 若输入数字为“23”，则路径可形象表示为：
    //     a          b        c 
    //   / | \      / | \    / | \
    //  d  e  f    d  e  f  d  e  f
    void dfs( string& dig, vector<string>& m, vector<string>& ret, string& p, int dep){
        // reach the bottom, one path ends
        if(dep == dig.size()){
            ret.push_back(p);
        }
        else{
            for(int i = 0; i < m[dig[dep] - '0'].size(); i++){
                p.push_back(m[dig[dep] - '0'][i]);
                dfs(dig, m, ret, p, dep + 1);
                p.pop_back(); // backtracking
            }
        }
    }
};
