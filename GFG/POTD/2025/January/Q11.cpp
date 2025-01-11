#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int arr[26];
        for(int i=0;i<26;i++)arr[i]=-1;
        int n=s.size();
        int i=0,j=0,maxi=-1;
        while(j<n)
        {
            int id=arr[s[j]-'a'];
            if(id!=-1)
            {
                 maxi=max(maxi,j-i);
                 while(i<=id)
                 {
                     arr[s[i]-'a']=-1;
                     i++;
                 }
                 
                 
            }
            arr[s[j]-'a']=j;
            j++;
        }
        maxi=max(maxi,j-i);
        return maxi;
        
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        
       Solution obj;
       string s;
       cin>>s;
       cout<<obj.longestUniqueSubstr(s)<<endl;
       cout<<endl;
    }
    
    return 0;
}