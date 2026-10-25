class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size()%groupSize!=0) return false;

        unordered_map<int,int>mp;
        for(int cnt:hand){
            mp[cnt]++;
        }

        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(auto count:mp){
            minHeap.push(count.first);
        }
        while(!minHeap.empty()){
            int first=minHeap.top();

            for(int i=first;i<first+groupSize;i++){
                if(mp.find(i)==mp.end()) return false;

                mp[i]-=1;
                if(mp[i]==0){
                        if(i!=minHeap.top()) return false;
                        minHeap.pop();
                    }
            }
        }
        return true;


        
        
    }
};