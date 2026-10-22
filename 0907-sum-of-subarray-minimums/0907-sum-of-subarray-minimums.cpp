class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;

        vector<int>next(n);
        vector<int>prev(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }

            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }

           while (!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }
            st.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-prev[i];
            long long right=next[i]-i;

            long long contribution=(1LL*arr[i]*left%mod)*right%mod;

            ans=(ans+contribution)%mod;
        }

        return ans;



    }


};