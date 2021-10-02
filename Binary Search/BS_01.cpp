#include<bits/stdc++.h>
using namespace std;

//binary search for ascending sorted array
int binarySerach(int ele ,vector<int>arr)
{
    int start=0;
    int end=arr.size();
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==ele)
        {
            return mid;
        }
        else if (ele<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    return -1;
}


//binary search for first occurance of element if it exist for more than one time
int binarySerachfirstOcc(int ele ,vector<int>arr)
{
    int start=0;
    int end=arr.size();
    int res=-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==ele){
            res=mid; 
            end=mid-1;
        }
        else if (ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }  
    }
    return res;
}

//binary search for last occurance of element if it exist for more than one time
int binarySerachlastOcc(int ele ,vector<int>arr)
{
    int start=0;
    int end=arr.size();
    int res=-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==ele){
            res=mid;
            start=mid+1;

        }
        else if (ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}
//count of occurence of a element in the array 
int occurence(int ele,vector<int>vect)
{
    return binarySerachlastOcc(10,vect)-binarySerachfirstOcc(10,vect)+1;
}

int main()
{
    
    vector<int> vect{ 2 ,4,10,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,1010,10,10,10,10,10,10,10,10,10,10,10,18,20};
    cout<<binarySerach(20,vect)<<endl;
    cout<<binarySerachfirstOcc(10,vect)<<endl;
    cout<<binarySerachlastOcc(10,vect)<<endl;
    cout<<occurence(10,vect)<<endl;
    
    
    return 0;
}