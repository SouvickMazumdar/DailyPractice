// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include<bits/stdc++.h>;
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long n=arr.size();
        vector<long>vr(n);
        vr[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            vr[i]=vr[i-1]^arr[i];
        }
        unordered_map<long,long>mp;
        long cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vr[i]==k)cnt++;
            if(mp.count(vr[i]^k)!=0)
            {
                cnt+=mp[vr[i]^k];
            }
            mp[vr[i]]++;
            
        }
        return cnt;
    }
};