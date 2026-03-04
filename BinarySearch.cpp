#include<iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter array size: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n << " sorted elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int mid;
    bool found = false;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            cout << "Found at position " << mid + 1;
            found = true;
            break;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(!found)
        cout << "Not Found";

    return 0;
}
