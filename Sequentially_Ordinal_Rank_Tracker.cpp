#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,string>, null_type,less<pair<int,string>>, rb_tree_tag,tree_order_statistics_node_update>

class SORTracker {
    ordered_set tracks;
    int index;
public:
    SORTracker() {
        tracks.clear();
        index=0;
    }
    
    void add(string name, int score) {
        tracks.insert({-score,name});
    }
    
    string get() {
        pair<int,string> cur=*(tracks.find_by_order(index));
        ++index;
        return cur.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
