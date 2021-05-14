class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int lim=(int)a.size()+5;
        vector<bool> check(lim);
        for(int i=0;i<(int)a.size();++i){
            if(a[i]>0&&a[i]<lim) check[a[i]]=1;
        }
        for(int i=1;i<lim;++i){
            if(!check[i]) return i;
        }
           
        return -1;
    }
};
