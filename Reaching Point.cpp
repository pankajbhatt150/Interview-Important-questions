Given coordinates of a source point (x1, y1) determine if it is possible to reach the destination point (x2, y2). From any point (x, y) there only two types of valid movements: 
(x, x + y) and (x + y, y). Return a boolean true if it is possible else return false. 
Note: All coordinates are positive. 
Asked in: Expedia, Telstra
Examples: 
 

Input : (x1, y1) = (2, 10)
        (x2, y2) = (26, 12)
Output : True
(2, 10)->(2, 12)->(14, 12)->(26, 12) 
is a valid path.

Input : (x1, y1) = (20, 10)
        (x2, y2) = (6, 12)
Output : False
No such path is possible because x1 > x2
and coordinates are positive
// Solution
// C++ program to check if a destination is reachable
// from source with two movements allowed
#include <bits/stdc++.h>
using namespace std;
 
bool isReachable(int sx, int sy, int dx, int dy)
{
    // base case
    if (sx > dx || sy > dy)
        return false;
 
    // current point is equal to destination
    if (sx == dx && sy == dy)
        return true;
 
    // check for other 2 possibilities
    return (isReachable(sx + sy, sy, dx, dy) ||
            isReachable(sx, sy + sx, dx, dy));
}
 
// Driver code
int main()
{
    int source_x = 2, source_y = 10;
    int dest_x = 26, dest_y = 12;
    if (isReachable(source_x, source_y, dest_x, dest_y))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
