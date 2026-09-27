class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int rank=0;
        int prev=INT_MIN;
        while(!pq.empty()){
           int value=pq.top().first;
           int index=pq.top().second;;
           pq.pop();

           if(value!=prev){
            rank++;
            prev=value;
           }
           arr[index]=rank;
            }
        return arr;
    }
};