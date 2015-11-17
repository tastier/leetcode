class Solution {
private:
    #define INT_MAX  2147483647;
    #define INT_MIN -2147483648;
    bool is_number(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
public:
    int myAtoi(string str) {
        int ret = 0;
        int i = 0;
        bool sign; // true is '+' and false is '-'
        
        //delete space
        for(i = 0; i < str.size(); i++){
            if(str[i] == ' ')
                continue;
            break;
        }
        //deal sign
        if( is_number(str[i]) ){
            sign = true;
        }
        else if(str[i] == '+'){
            sign = true;
            ++i;
        }
        else if(str[i] == '-'){
            sign = false;
            ++i;
        }
        else
            return 0; //illegal
            
        //delete 0, don't need this
        // for(; i < str.size(); ++i){
        //     if(str[i] == '0')
        //         continue;
        //     break;
        // }
        
        //deal numbers
        for(; i < str.size(); ++i){
            if( !is_number(str[i]) )
                return ret;
            if(sign == true){
                if( ret > 214748364 || (ret == 214748364 && (str[i] - 48) > 7) ) // overflow参考了solution
                    return INT_MAX;
                ret = ret * 10 + (str[i] - 48);
            }
            if(sign == false){
                if( ret < -214748364 || (ret == -214748364 && (str[i] - 48) > 8) )
                    return INT_MIN;
                ret = ret * 10 - (str[i] - 48);
            }
        }
        return ret;
    }
};
