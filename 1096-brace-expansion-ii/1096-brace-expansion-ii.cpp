class Solution {
public:
    string s;
    int n;
    int idx;

    set<string> getUnit(){
        set<string> result;

        if(s[idx] == '{'){
            idx++;
            result = performUnion();
        }else{
            result = {string(1, s[idx])};
        }

        idx++;
        return result;
    }

    set<string> performConcat(){
        set<string> result = {""};

        while(idx<n &&  s[idx]=='{' || isalpha(s[idx])){
            set<string> temp = getUnit();

            set<string> concatRes;

            for(const string& left:result){
                for(const string& right: temp){
                    concatRes.insert(left+right);
                }
            }

            result = concatRes;
        }
        return result;
    }

    set<string> performUnion() {
        set<string> result;

        while (true) {
            set<string> temp = performConcat();
            result.insert(begin(temp), end(temp));

            if (idx < n && s[idx] == ',')
                idx++;
            else
                break;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        n = expression.length();

        set<string> st = performUnion();
        vector<string> result(begin(st), end(st));

        return result;
    }
};