class Solution {
public:
    int DaysReq(int cap, vector<int>&weights, int n){
        int Days=1,load=0;
        for(int i=0;i<n;i++){
           if(load+weights[i]>cap){
            Days++;
            load=weights[i];
           }
           else{
            load+=weights[i];
           }
        }
        return Days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int n=weights.size(),sum=0,ans=INT_MAX;
        for(int i=0;i<n;i++){
           sum+=weights[i];
        }
        int high=sum;
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            int daysReq=DaysReq(mid,weights,n);
            if(daysReq<=days){
                ans=min((int)mid,ans);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};