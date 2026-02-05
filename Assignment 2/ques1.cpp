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
    int N = 6;

    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    Activity activities[6];

    for (int i = 0; i < N; i++) {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    // Sort by finish time
    sort(activities, activities + N, compare);

    int count = 1;
    int lastFinish = activities[0].finish;

    cout << "Selected activities: ";
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")";

    for (int i = 1; i < N; i++) {
        if (activities[i].start >= lastFinish) {
            cout << ", (" << activities[i].start << ", " << activities[i].finish << ")";
            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;
    return 0;
}
