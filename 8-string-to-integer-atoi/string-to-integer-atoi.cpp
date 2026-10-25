class Solution {
public:
    bool isDigit(char c){
        if(c>='0'&&c<='9') return true;
        return false;
    }
    int myAtoi(string s) {
        int n=s.size();
        int num=0;
        int sign=+1; //default is positive, -1 for negative
        int i=0;
        //1. Ignoring White spaces
        while(i<n&&s[i]==' '){
            i+=1;
        }
        // 2. Signedness
        if(i<n){
            if(s[i]=='-'){
                sign=-1;
                i+=1;
            }
            else if(s[i]=='+'){
                 i+=1;
            }
        }
        //3. Conversion
        while(i<n&&isDigit(s[i])){
            int digit=s[i]-'0';
            //rounding
            //// Check overflow before multiplying by 10 
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) { 
                return sign == 1 ? INT_MAX : INT_MIN; 
            }
            num=num*10+digit;
            i+=1;
        }
        return sign*num;
    }
};