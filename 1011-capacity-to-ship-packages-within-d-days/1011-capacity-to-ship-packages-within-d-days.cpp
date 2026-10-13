class Solution {
public:
int f(vector<int>&weights,int days){
    int n=weights.size();
int cnt=1;
int loads=0;
    for(int i=0;i<n;i++){

        if(loads+weights[i]>days){
            cnt++;
            loads=weights[i];
        }
        else{
            loads+=weights[i];
        }
    }
    return cnt;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxCapacity=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(weights[i],maxi);
            maxCapacity+=weights[i];
        }
        int low=maxi;
        int high=maxCapacity;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            int total=f(weights,mid);

            if(total<=days){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};