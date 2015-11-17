class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        // if(x >= 0 && x <= 9)
        //     return true;
            
        int div = x;
        int reverse = 0;
        while( div != 0 ){
            if(reverse >= 214748364) // Whether the program handles overflowing or not, it could be accepted. 
                return false;
            reverse = reverse * 10 + div % 10;
            div = div / 10;
        }
        return reverse == x;
    }
};
