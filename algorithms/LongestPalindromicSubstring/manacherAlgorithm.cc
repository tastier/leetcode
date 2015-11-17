class Solution {
public:
    string longestPalindrome(string str) {
    int len=str.length();
    if(len<=1)return str;
    string str1=str;
    reverse(str1.begin(),str1.end());
    if(str1==str)
        return str;
    string s;
    s += "$#";
    for(int i = 0; i < len; i++){
        s += str[i];
        s += "#";
    }
    s +="$";
    int n=s.size();
    int mx=0,Maxl=0,id=0;
    int *p = new int[n];
    memset(p,0,sizeof(p));
    for(int i=1;i<n-1;i++){
        p[i]=mx>i?min(mx-i,p[2*id-i]):1;
        while(s[i-p[i]]==s[i+p[i]])
            p[i]++;
        if(p[i]>mx-i){
            mx = p[i]+i;
            id=i;
        }
        Maxl=max(Maxl,p[i]);
    }
    int mid=0;
    for(int i=0;i<n;i++){
        if(p[i]==Maxl)
            mid=i;
    }
    int size=Maxl-1;
    delete []p;
    if(mid%2==0)
        return str.substr(mid/2-size/2-1,size);
    else
        return str.substr((mid-size-1)/2,size);
    }
};
