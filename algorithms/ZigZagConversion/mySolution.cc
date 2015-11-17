class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        int d1 = numRows - 3;
        int d2 = 0;
        //do nothing
        if(numRows == 1 || numRows >= s.size()) return s;
        
        for(int row = 1; row <= numRows; row++){
            if(row == 1 || row == numRows){
                ret = ret + print(s, row - 1, numRows - 2, -1);
                continue;
            }
            ret += print(s, row - 1, d1--, d2++);
        }
        return ret;
    }
private:
    string print(string &s, int start, int d1, int d2)
    {
        string ret;
        bool flag = true;
        
        for(int i = start; i < s.size(); ){
            ret += s[i];
            if(flag || d2 == -1){
                i = i + dis2index(d1);
            }
            else{
                i = i + dis2index(d2);
            }
            flag = !flag;
        }
        return ret;
    }
    int dis2index(int d)
    {
        return 2 * ( d + 1 );
    }
};
