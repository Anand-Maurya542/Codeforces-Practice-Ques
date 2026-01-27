#include <bits/stdc++.h>
using namespace std;

 void getperms(vector<int> &nums,int index){
        if(index==nums.size()){
            for(auto num:nums){
                cout<<num;
            };
            cout<<endl;
            // cout<<endl<<index<<endl;
            return;
        }
        for(int i=index;i<nums.size();i++){
            cout<<index<<endl;
        swap(nums[index],nums[i]);
         for(auto num:nums){
                cout<<num;
            };
            cout<<endl;
        getperms(nums,index+1);
         for(auto num:nums){
                cout<<num;
            };
            cout<<endl;
        swap(nums[index],nums[i]);
         
    }
    }
int main(){
    // string str;
    // getline(cin,str);
    // cout<<str;

    // int arr[256]={};
    // cout<<arr[0];
    // return 0;

            // vector<int> nums;
            // nums={1,2,3};

   
            // // vector<vector<int>> ans;
            // getperms(nums,0);
            int a;
            cin>>a;
            cout<<a;
    
    
    
}