#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Calculate the number of screens needed for 2x2 icons
        int screensFor2x2 = ceil(y / 2.0);
        
        // Calculate the remaining 1x1 icons that need to be placed
        // Each 2x2 icon uses up 4 cells, so we effectively use up 2 cells per 2x2 icon
        // since we are calculating for screens.
        int remaining1x1 = x + (y % 2) * 2; // Adding extra space if an odd 2x2 icon is placed
        
        // Calculate the number of screens needed for 1x1 icons
        int screensFor1x1 = ceil(remaining1x1 / 15.0);
        
        // Total screens needed is the sum of both
        int totalScreens = screensFor2x2 + screensFor1x1;
        
        cout << totalScreens << endl;
    }
    return 0;
}
