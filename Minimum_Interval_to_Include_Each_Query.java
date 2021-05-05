class Solution {
    // static final int N=10000005;
    // static final int INF=1000000009;
    // static final int LIM=10000000;
    // class SegmentTree{
    //     int []seg;
    //     int []lazy;
    //     SegmentTree(int n){
    //         seg=new int[n*2];
    //         lazy=new int[n*2];
    //         Arrays.fill(seg,INF);
    //         Arrays.fill(lazy,INF);
    //     }
    //     public int min(int a,int b){
    //         return Math.min(a,b);
    //     }
    //     public void pushdown(int id){
    //         int val=lazy[id];
    //         seg[id*2]=min(seg[id*2],val);
    //         lazy[id*2]=min(lazy[id*2],val);
    //         seg[id*2+1]=min(seg[id*2+1],val);
    //         lazy[id*2+1]=min(lazy[id*2+1],val);
    //         lazy[id]=INF;
    //     }
    //     public void update(int id,int l,int r,int beg,int fin,int val){
    //         if(fin<l||r<beg) return;
    //         if(beg<=l&&r<=fin){
    //             seg[id]=min(seg[id],val);
    //             lazy[id]=min(lazy[id],val);
    //             return;
    //         }
    //         int mid=(l+r)>>1;
    //         pushdown(id);
    //         update(id*2,l,mid,beg,fin,val);
    //         update(id*2+1,mid+1,r,beg,fin,val);
    //         seg[id]=min(seg[id*2],seg[id*2+1]);
    //     }
    //     public int getMin(int id,int l,int r,int beg,int fin){
    //         if(fin<l||r<beg) return INF;
    //         if(beg<=l&&r<=fin){
    //             return seg[id];
    //         }
    //         int mid=(l+r)>>1;
    //         pushdown(id);
    //         return min(getMin(id*2,l,mid,beg,fin),getMin(id*2+1,mid+1,r,beg,fin));
    //     }
    // }
    
    public int[] minInterval(int[][] a, int[] que) {
        int n=a.length;
        int m=que.length;
        int[] ans=new int[m];
        TreeMap<Integer,Integer> PQ=new TreeMap<>();
        HashMap<Integer,Integer> hash=new HashMap<>();
        int []queClone=que.clone();
        Arrays.sort(a,(A,B)->Integer.compare(A[0],B[0]));
        Arrays.sort(queClone);
        int i=0;
        for(int q:queClone){
            while(i<n&&a[i][0]<=q){
                int l=a[i][0];
                int r=a[i][1];
                ++i;
                PQ.put(r-l+1,r);
            }
            while(!PQ.isEmpty()&&PQ.firstEntry().getValue()<q){
                PQ.pollFirstEntry();
            }
            if(PQ.isEmpty()){
                hash.put(q,-1);
            }
            else{
                hash.put(q,PQ.firstKey());
            }
        }
        i=0;
        for(int q:que){
            ans[i]=hash.get(q);
            ++i;
        }
        return ans;
    }
}
