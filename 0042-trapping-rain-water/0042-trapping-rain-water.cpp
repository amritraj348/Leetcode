class Solution {
public:
    int trap(vector<int>& height) {
        int Lmax=0;
        int Rmax=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        int total=0;

        while(l<r){
            if(height[l]<height[r]){
                if(Lmax>height[l]){
                    total+=Lmax-height[l];
                }
                else{
                    Lmax=height[l];
                }
                l=l+1;
            }
            else{
                if(Rmax>height[r]){
                    total+=Rmax-height[r];
                }
                else{
                    Rmax=height[r];
                }
                r=r-1;
            }
        }
        return total;
    }
};