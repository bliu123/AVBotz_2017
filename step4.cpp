#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int arc, char** argv)
{
    //Only works if the points are in a plane with a 1 meter grid length.
    double time1, time2, time3, x1, x2, x3, y1, y2, y3, distance1, distance2, source_x, source_y, equation1_x, equation1_y, equation2_x, equation2_y, least_x, least_y;
    int close;
    cout << "Input time differences: \n";
    cin >> time1 >> time2 >> time3;
    cout << "Input x-coordinates: \n";
    cin >> x1 >> x2 >> x3;
    cout << "Input y-coordinates: \n";
    cin >> y1 >> y2 >> y3;
    
    
    if (time1 < time2 && time1 < time3)
    {
        close = 1;
        least_x = x1;
        least_y = y1;
    }
    if (time2 < time1 && time2 < time3)
    {
        close = 2;
        least_x = x2;
        least_y = y2;
    }
    if (time3 < time1 && time3 < time2)
    {
        close = 3;
        least_x = x3;
        least_y = y3;
    }
    
    switch (close)
    {
        case 1:
            if (time2 < time3)
            {
                distance1 = time2 - time1;
                distance2 = time3 - time1;
                equation1_x = x2;
                equation1_y = y2;
                equation2_x = x3;
                equation2_y = y3;
            }
            else
            {
                distance1 = time3 - time1;
                distance2 = time2 - time1;
                equation1_x = x3;
                equation1_y = y3;
                equation2_x = x2;
                equation2_y = y2;
            }
        case 2:
            if (time1 < time3)
            {
                distance1 = time1 - time2;
                distance2 = time3 - time2;
                equation1_x = x1;
                equation1_y = y1;
                equation2_x = x3;
                equation2_y = y3;
            }
            else
            {
                distance1 = time3 - time2;
                distance2 = time1 - time2;
                equation1_x = x3;
                equation1_y = y3;
                equation2_x = x1;
                equation2_y = y1;
            }
        case 3:
            if (time1 < time2)
            {
                distance1 = time1 - time3;
                distance2 = time2 - time3;
                equation1_x = x1;
                equation1_y = y1;
                equation2_x = x2;
                equation2_y = y2;
            }
            else
            {
                distance1 = time2 - time3;
                distance2 = time1 - time3;
                equation1_x = x2;
                equation1_y = y2;
                equation2_x = x1;
                equation2_y = y1;
            }
    }
    
    distance1 *= 1481;
    distance2 *= 1481;
    
    for (source_x = -1; source_x <= 1; source_x += .01)
        {
        for (source_y = -1; source_y <= 1; source_y += .01)
            {
                //Find the most accurate x and y values.
            }
        }
    cout << "(" << source_x << "," << source_y << ")";
}
