#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};


bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }


    sort(arr, arr + n, compare);

    cout << "Selected activities:\n";

    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }

    return 0;
}
