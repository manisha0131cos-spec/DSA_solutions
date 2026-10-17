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
        int n=weights.size();
        int high=accumulate(weights.begin(),weights.end(),0); //fun for sum of all elements of array weights
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            int daysReq=DaysReq(mid,weights,n);
            if(daysReq<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};