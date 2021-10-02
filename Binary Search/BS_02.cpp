//algorithms for no of times  sorted array array rotated
//logic is if the minimum element is at start then array is 0 times rotated
//if min is at end then array is rotated once //i.e. (size-index)%size
// if mim element is at mid, size 8 (0,7) and mid 3 then rotation is 4
// rotation are front to back
//task : if the rotations are 

#include <bits/stdc++.h>
using namespace std;

//count of no. of rotation of sorted array
int binarySearch(vector<int> v, int size)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {

        mid = start + (end - start) / 2;
        if (v[start] <= v[end])
        {
            return start;
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
int main()
{
    vector<int> vect{11, 12, 15, 18, 2, 8, 9, 10};
    cout << "Total no. of rotations are : " << binarySearch(vect, 7) << endl;

    return 0;
}