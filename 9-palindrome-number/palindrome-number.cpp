class Solution {
public:
    bool isPalindrome(int x) {
        long long sum=0;
        if(x<0) return false;
        int n=x;
        while(n>0){
           sum=sum*10+n%10;
           n=n/10;
        }
        if(sum==x) return true ;
        else return false;
    }
};