class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int count=0,n=s.size();
        for(int i=0;i<n;i++){
           if(s[i]=='('){
            count++;
            depth=max(depth,count);
           }
           if(s[i]==')') count--;
        }
        return depth;
    }
};