class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int missing,low=0,high=n-1;
        while(low<=high){
            long long mid=(long long)(low+high)/2;
            missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;
        }
        return (high+k+1); //or low+k
    }
};