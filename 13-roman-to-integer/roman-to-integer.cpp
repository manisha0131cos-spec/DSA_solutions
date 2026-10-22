class Solution {
public:
    int NUM(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else if(c=='M') return 1000;
        else return -1;
    }
    int romanToInt(string s) {
        int n=s.size();
        int sum=0,i=0;
        while(i<n-1){
            if(NUM(s[i])>=NUM(s[i+1])){
               sum+=NUM(s[i]);
            }
            else{
                sum=sum-NUM(s[i]);
            }
            i++; 
        }
        sum+=NUM(s[n-1]);
        return sum;
    }
};