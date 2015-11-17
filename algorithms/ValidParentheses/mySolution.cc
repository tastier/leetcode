class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)
            return false;
        stack<char> sk;
        for(int i = 0; i < s.size(); i++){
            if(isLeft(s[i]))
                sk.push(s[i]);
            else{
                if(sk.size() == 0)
                    return false;
                if( match(sk.top(), s[i]) )
                    sk.pop();
                else
                    return false;
            }
        }
        if(sk.size() != 0)
            return false;
        return true;
    }
private:
    bool match(char a, char b){
        if( (a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']') )
            return true;
        return false;
    }
    bool isLeft(char c){
        if(c == '(' || c == '{' || c == '[')
            return true;
        return false;
    }
};
