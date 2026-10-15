class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       int m=mat.size();
       int n=mat[0].size();
       int row=-1;
       int maxOnes=-1;
       for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                cnt++;
            }
        }
        if(cnt>maxOnes){
            maxOnes=cnt;
            row=i;
        }
       }
       return {row,maxOnes};
    }
};