//sorting an array using recursion
//bubble sort
//Sorting algorithms

#include<bits/stdc++.h>
using namespace std;


class solution
{
    private:
    
    public:
    void SortRec(vector<int>& v)
    {
        if(v.size()==1)
        {
            return;
        }
        //reducing the input by removing the last elemenet and storing it for inserting at correct pos
        int temp=v[v.size()-1];
        v.pop_back();
        SortRec(v); //applying on reduced input vector
        insertCor(v,temp); //for inserting poped element at correct position
        
    }
    
    //taking input to function by reference so the changes will be reflected every where
    void insertCor(vector<int>& v,int temp)
    {
        //base case of recursion
        if(v.size()==0 || v[v.size()-1]<=temp)
        {
            v.push_back(temp);
            return;
        }
        //hypothesis i.e. reducing the input decomposing all
        int value=v[v.size()-1];
        v.pop_back();
        insertCor(v,temp);
        //induction step means recombining all again
        v.push_back(value);
        
    }
};
int main()
{
    solution s;
    vector<int>vect;
    cout<<"Enter the size :";
    int n;
    cin>>n;
    cout<<"Enter the Elenents : ";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin>>k;
        vect.push_back(k);
    }
    
    s.SortRec(vect);
    cout<<"Sorted Array : ";
    for(auto x:vect)
    {
        cout<<x<<" ";
    }
    
    return 0;
}