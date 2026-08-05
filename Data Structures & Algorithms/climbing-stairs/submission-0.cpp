   
//using memoiation technizue
    class Solution {
    public:
        int climbStairs(int n) {
            vector<int> store(n+1,-1);       //storage is (n+1) : number starts from 0
            int ans=solve(n,store);
            return ans;
        }

        int solve(int n,vector<int>& store){
            if(n==0 || n==1){
                return 1;
            }

            if(store[n]!=-1){
                return store[n];
            }

            return store[n]=solve(n-1,store)+solve(n-2,store);
        }
    };