class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int n=nums.size();
       int low=1,ans=INT_MAX;
       int high=*max_element(nums.begin(), nums.end());
       while(low<=high){
        long long mid=(long long)(low+high)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/mid);
        }
        if(sum<=threshold){
            ans=min((int)mid,ans);
            high=mid-1;
        }
        else low=mid+1;
        }
        return ans;
    }
};