class Solution {
public:
    void getBest(int& ansl, int& ansr, int l, int r){
        if(ansr-ansl+1 > r-l+1){
            ansr = r;
            ansl = l;
            //cout<<"Something wrong??\n";
        }
    }
    string minWindow(string s, string t) {
        array<int, 128> freq{};
        int n= t.size(),cnt= 0;
        for(char& ch : t)
            freq[ch]++;
        
        int l=0, r=0;
        int ansl=-1000000,ansr=1000000;
        while(r < s.size()){
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;
            if(cnt == n){
                getBest(ansl, ansr, l, r);
                while(cnt == n && l<=r){
                    getBest(ansl, ansr, l, r);
                    freq[s[l]]++;
                    if(freq[s[l]]>0) cnt--;
                    l++;
                }
            }
            r++;
        }
        //cout<<"ansl="<<ansl<<",ansr="<<ansr<<"\n";
        if(ansr-ansl+1 > 100000){
            return "";
        } 
        string ans;
        for(int i=ansl;i<=ansr;i++)
            ans.push_back(s[i]);
        return ans;
    }
};
