//find the element in the sorted rotated array

#include <bits/stdc++.h>
using namespace std;

//count of no. of rotation of sorted array
int CountOfRotation(vector<int> v)
{
    int size = v.size();
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {

        mid = start + (end - start) / 2;
        if (v[start] <= v[end])
        {
            return (size - start) % size;
        }
        else
        {

            int next = (mid + 1) % size;
            int prev = (mid + size - 1) % size;
            if (v[mid] <= v[prev] && v[mid] <= v[next]) //the element should be less than both
            {
                return (size - mid) % size;
            }
            //now we have to move to the unsorted array which is (start ,mid) || (mid,end)
            else if (v[start] <= v[mid])
            {
                //first part is sorted move to next half i.e start=mid+1
                start = mid + 1;
            }
            else if (v[mid] <= v[end])
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int BinarySearch(vector<int> v, int start, int end, int target)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (target < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vect{11, 12, 15, 18, 2, 3, 4, 5, 6, 6};
    int n = vect.size();
    cout << "Total no. of rotations are : " << CountOfRotation(vect) << endl;
    int pivot = n - CountOfRotation(vect);
    int target = 2;
    cout << "Element is At location :" << BinarySearch(vect, 0, pivot - 1, target) + BinarySearch(vect, pivot, n, target) + 1 << endl;
    return 0;
}