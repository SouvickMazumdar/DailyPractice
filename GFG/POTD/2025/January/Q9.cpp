#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0,j=0,sum=0, n=arr.size();
        while(i<=j && j<n)
        {
            sum+=arr[j];
            j++;
            if(sum==target)
            {
                return {i+1,j};
            }
            while(sum>target)
            {
                sum-=arr[i];
                i++;
                if(sum==target)
                return {i+1,j};
            }
        }
        return {-1};
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<int>arr;
        int d;
        string s;
        getline(cin,s);
        stringstream ss(s);
        int n;
        while(ss>>n)
        {
            arr.push_back(n);
        }
        cin>>d;
        cin.ignore();
        Solution obj;
        vector<int> ans = obj.subarraySum(arr,d);   
        for(int i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}