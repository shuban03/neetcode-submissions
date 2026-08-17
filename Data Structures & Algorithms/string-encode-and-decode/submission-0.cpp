class Solution {
public:

    string encode(vector<string>& strs) {
           string res="";
           for(auto str:strs){
            res+=to_string(str.length())+"#"+str;
           }
           return res;
    }

    vector<string> decode(string s) {
         vector<string> res;
         int i=0;
         while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,i-j));
            i=j+1;
            res.push_back(s.substr(i,length));
            i=i+length;
            j=i;
           
         }
          return res;
    }
};
