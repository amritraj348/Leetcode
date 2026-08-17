class Solution {
public:

int func(vector<int>&weights,int mid){
    int day=1;
    int load=0;
    for(int i=0;i<weights.size();i++){

        if(load+weights[i]>mid){
            day+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return day;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=INT_MIN;
        int maxCapacity=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,weights[i]);
            maxCapacity+=weights[i];
        }

        int low=maxi;
        int high=maxCapacity;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            int totalDays=func(weights,mid);

            if(totalDays<=days){
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