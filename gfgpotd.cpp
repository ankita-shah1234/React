class Solution {
  public:
      vector<int> getnsl(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int>st;
          
          for(int i =0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }else{
                while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
                result[i]=st.empty()?-1:st.top();
            }
            st.push(i);
          }
            return result;
          }


    vector<int>getnsr(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int>st;
          
          for(int i =n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }else{
                while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                result[i]=st.empty()?n:st.top();
            }
            st.push(i);
          }
            return result;
          }
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nls = getnsl(arr,n);
        vector<int> nrs = getnsr(arr,n);
        
        long long sum =0;
        int M = 1e9+7;
        
        for(int i =0; i<n;i++){
        int l = i-nls[i];
        int r = nrs[i]-i;
        
        long long totalsub =1LL* l*r;
        long long totalsum= 1LL*arr[i]*totalsub;
         
         sum = (sum+totalsum)%M;
        }
        return sum;
    }
};
