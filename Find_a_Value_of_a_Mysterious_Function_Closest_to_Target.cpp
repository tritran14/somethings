class Solution {
public:
    int closestToTarget(vector<int>& a, int target) {
        int sum=a[0];
        int ans=1e9;
        for(int x:a){
            if(sum<target) sum=x;
            sum&=x;
            ans=min(ans,abs(target-sum));
        }
        return ans;
    }
};
