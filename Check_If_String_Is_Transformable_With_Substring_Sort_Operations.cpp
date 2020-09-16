class Solution {
public:
    bool check1(string s,string t){
        vector<int> numS(10),numT(10);
        for(int i=0;i<s.size();++i){
            ++numS[s[i]-'0'];
            ++numT[t[i]-'0'];
        }
        return numS==numT; 
    }
    
    bool isTransformable(string s, string t) {
        if(!check1(s,t)) return 0;
        vector<int> last[10];
        int n=(int)s.size();
        for(int i=0;i<n;++i){
            last[s[i]-'0'].push_back(i);
        }
        for(int i=n-1;i>=0;--i){
            int num=t[i]-'0';
            if(last[num].empty()) return 0;
            int id=last[num].back();
            last[num].pop_back();
            for(int bigger=num+1;bigger<10;++bigger){
                if(last[bigger].empty()) continue;
                if(last[bigger].back()>id) return 0;
            }
        }
        return 1;
    }
};
