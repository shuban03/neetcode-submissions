class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans="";
        helper(res,ans,n,0,0);
        return res;
    }

    void helper(vector<string>& res,string& ans,int n,int openN,int closeN){
       if(openN==closeN && openN==n){
        res.push_back(ans);
       }
       if(openN<n){                               //for '('
        ans+='(';                                 //addd
        helper(res,ans,n,openN+1,closeN);         //explore
        ans.pop_back();                           //remove
       }
       if(closeN<openN){                           //for ')'
        ans+=')';                                  //addd
        helper(res,ans,n,openN,closeN+1);          //explore
        ans.pop_back();                            //remove
       }
    } 
};