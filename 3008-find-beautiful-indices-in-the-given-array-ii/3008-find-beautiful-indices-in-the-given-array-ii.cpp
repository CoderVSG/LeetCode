#define pb push_back
class Solution {
public:
    vector<int>oa,ob;
    string aa,bb;
    void computeLPSArray(vector<int> pat, int M, int* lps) {
        int len = 0, i = 1;
        lps[0] = 0;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int KMPSearch1(vector<int> pat, vector<int> txt) {
        int M = pat.size(), N = txt.size();
        int lps[M];
        computeLPSArray(pat, M, lps);
        int i = 0, j = 0, ans = 0;
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == M) {
                oa.push_back(i-aa.size());
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) j = lps[j - 1];
                else i = i + 1;
            }
        }
        return ans;
    }
    int KMPSearch2(vector<int> pat, vector<int> txt) {
        int M = pat.size(), N = txt.size();
        int lps[M];
        computeLPSArray(pat, M, lps);
        int i = 0, j = 0, ans = 0;
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == M) {
                ob.push_back(i-bb.size());
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) j = lps[j - 1];
                else i = i + 1;
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if(s.size()<a.size() || s.size()<b.size())return {};
        oa.clear();ob.clear();aa=a;bb=b;
        vector<int>t1,t2,t3;
        for(auto i:s)t1.pb(i-'a');
        for(auto i:a)t2.pb(i-'a');
        for(auto i:b)t3.pb(i-'a');
        int val1=KMPSearch1(t2,t1);
        int val2=KMPSearch2(t3,t1);
        vector<int>ans;
        for(int i=0;i<oa.size();i++){
            int val=oa[i]-k;
            auto it=lower_bound(ob.begin(),ob.end(),val);
            if(it!=ob.end()){
                int x=it-ob.begin();
                if(ob[x]<=oa[i]+k)ans.push_back(oa[i]);
            }
        }
        return ans;
    }
};