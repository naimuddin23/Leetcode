class Solution {
public:
    string shortestPalindrome(string s) {
      string p=s;
        reverse(p.begin(),p.end());
        p=s+"#"+p;
        vector<int> next(p.size()+1,0); //
        getNext(p,next);
        return p.substr(s.size()+1,s.size()-next.back())+s;
    }
    //prefix suffix match, O(N)
    void getNext(string &p, vector<int> &next){
        next[0]=-1;
        int k=-1,j=0,len=next.size();
        while(j<len-1){
            //p[k] denotes prefix, p[j] denotes suffix
            if(k==-1||p[j]==p[k])next[++j]=++k;
            else k=next[k];
        }   
        
    }
};