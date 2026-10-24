class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int rank=0;
            int prev=INT_MIN;
        while(!pq.empty()){
            int index=pq.top().second;
            int value=pq.top().first;
            pq.pop();

            if(prev!=value){
                rank++;
                prev=value;
            }
            arr[index]=rank;

        }
        return arr;
    }
};