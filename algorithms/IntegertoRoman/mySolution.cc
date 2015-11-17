class Solution {
public:
//I（1）、V（5）、X（10）、L（50）、C（100）、D（500）M（1000）
//参考discuss中的java程序
    string intToRoman(int num) {
        int value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string s;
        for(int i = 0; i < 13; ++i){
            while(num >= value[i]){
                s += roman[i];
                num -= value[i];
            }
        }
        return s;
    }
};
