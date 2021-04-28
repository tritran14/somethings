class Solution {
public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        int n=(int)a.size();
        int m=(int)b.size();
        vector<int> ans;
        for(int i=0;i<=k;++i){
            int j=k-i;
            if(i>n||j>m) continue;
            ans=max(ans,merge(maxNumberWithLen(a,i),maxNumberWithLen(b,j)));
        }
        return ans;
    }
    
    vector<int> maxNumberWithLen(const vector<int>& a,int k){
        if(!k) return {};
        int need_pop=(int)a.size()-k;
        vector<int> ans;
        for(int x:a){
            while(!ans.empty()&&ans.back()<x&&need_pop-->0){
                ans.pop_back();
            }
            ans.push_back(x);
        }
        ans.resize(k);
        return ans;
    }
    vector<int> merge(const vector<int>& a,const vector<int>& b){
        vector<int> ans;
        auto s1 = a.begin();
        auto e1 = a.end();
        auto s2 = b.begin();
        auto e2 = b.end();
        while(s1!=e1||s2!=e2){
            if(lexicographical_compare(s1,e1,s2,e2)){
                ans.push_back(*s2);
                ++s2;
            }
            else{
                ans.push_back(*s1);
                ++s1;
            }
        }
        return ans;
    }
};
