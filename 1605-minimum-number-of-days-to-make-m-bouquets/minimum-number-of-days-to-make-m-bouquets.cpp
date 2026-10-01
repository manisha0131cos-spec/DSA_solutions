class Solution {
public:
    bool possible(vector<int>&arr, int day, int m, int k){
        int count=0,noofBouquets=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day) count++;
            else{
                noofBouquets+=(count/k);
                count=0;
            } 
        }
        noofBouquets+=(count/k);
        if(noofBouquets>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),ans=INT_MAX;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if(1LL*m*k>n) return -1;
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            if(possible(bloomDay,mid,m,k)==1){
                ans=min(ans,(int)mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};