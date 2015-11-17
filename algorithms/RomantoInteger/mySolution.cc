class Solution {
public:
//罗马数字转换成整数的正负号取决于它后面的罗马数字，大于后面的，则本数字为正，小于后面的则为负
//带着正负号将所有数字相加即是结果
    int romanToInt(string s) {
        int integer = 0;
        int num1 = 0, num2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(i == s.size() - 1){
                integer += r2i(s[i]);
                continue;
            }
            num1 = r2i(s[i]);
            num2 = r2i(s[i+1]);
            if(num1 >= num2)
                integer += num1;
            else
                integer -= num1;
        }
        return integer;
    }
private:
    int r2i(char c)
    {
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};
