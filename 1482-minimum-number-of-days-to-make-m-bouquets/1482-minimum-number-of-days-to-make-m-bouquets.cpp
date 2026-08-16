class Solution {
public:
int possible(vector<int>&bloomDay,int day,int m,int k){
    int cnt=0;
    int bouquet=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            cnt++;
            if(cnt==k){
                bouquet++;
                cnt=0;
            }
        }
        else{
            cnt=0;
        }
    }
    return bouquet;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m * k > n)
            return -1;

        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           int noOfBouquet= possible(bloomDay,mid,m,k);

           if(noOfBouquet >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};