class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end()),ans;
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            long long total_time=0;
            for(int i=0;i<n;i++){
                total_time+=ceil(piles[i]/(double)mid);
            }
            if(total_time<=h){
                ans= mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};