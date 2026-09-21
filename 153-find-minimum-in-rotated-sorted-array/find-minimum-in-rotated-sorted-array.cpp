class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mini=INT_MAX;
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            // little optimization
            // if search space is already sorted
            //then nums[low] will always be smaller in that search space
            if(nums[low]<=nums[high]){
                mini=min(nums[low],mini);
                break;
            }
            if(nums[low]<=nums[mid]){
                mini=min(nums[low],mini);
                low=mid+1;
            }
            else{
                mini=min(nums[mid],mini);
                high=mid-1;
            }
        }
        return mini;
    }
};