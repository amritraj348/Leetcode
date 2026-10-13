class Solution {
public:

int possible(vector<int>&bloomDay,int day,int m,int k){
int n=bloomDay.size();
int bouquet=0;
int cnt=0;
    for(int i=0;i<n;i++){
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
       int ans=0;
       if((long long)m*k>n) return -1;
       int mini=INT_MAX;
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
        mini=min(bloomDay[i],mini);
        maxi=max(bloomDay[i],maxi);
       }
       int low=mini;
       int high=maxi;

       while(low<=high){
        int mid=low+(high-low)/2;

        int noOfBouquet=possible(bloomDay,mid,m,k);

        if(noOfBouquet>=m){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return ans;
    }
};