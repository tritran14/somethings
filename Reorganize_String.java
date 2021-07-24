class Solution {
    public String reorganizeString(String s) {
        int[] cnt=new int[26];
        for(int i=0;i<s.length();++i){
            ++cnt[s.charAt(i)-'a'];
        }
        int maxx=0;
        int ch=0;
        for(int i=0;i<26;++i){
            if(maxx<cnt[i]){
                maxx=cnt[i];
                ch=i;
            }
        }
        if(maxx>s.length()-maxx+1){
            return "";
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<26;++i){
            if(ch!=i){
                for(int times=0;times<cnt[i];++times){
                    sb.append((char)(i+'a'));
                }
            }
        }
        // System.out.println("sb : "+sb.toString());
        StringBuilder prev=new StringBuilder();
        for(int i=0;i<maxx;++i){
            prev.append((char)(ch+'a'));
        }
        int turn=0;
        StringBuilder ans=new StringBuilder();
        while(sb.length()>0){
            if(turn==0){
                if(prev.length()>0){
                    ans.append(prev.charAt(0));
                    prev.deleteCharAt(0);
                }
                else{
                    prev.append(ans);
                    ans.setLength(0);
                }
            }
            else{
                ans.append(sb.charAt(0));
                sb.deleteCharAt(0);
            }
            turn^=1;
        }
        ans.append(prev);
        // System.out.println(ans.toString());
        return ans.toString();
    }
}
