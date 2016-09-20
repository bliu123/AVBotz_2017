#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int arc, char** argv)
{
    //Only works if the points are in a plane with a 1 meter grid length and if the sound originates from within the 100 by 100 meter grid.
    double time1, time2, time3, x1, x2, x3, y1, y2, y3, distance1, distance2, source_x, source_y, equation1_x, equation1_y, equation2_x, equation2_y, least_x, least_y, accuracy_a, accuracy_b, accuracy_c = 1000000000, real_source_x, real_source_y;
    int close;
    cout << "Input time differences for signals recieved at A, B, and C in seconds (the input for the first station to recieve a signal should be 0, and the inputs for the other two should be relative to the first): \n";
    cin >> time1 >> time2 >> time3;
    cout << "Input x-coordinates for A, B, and C: \n";
    cin >> x1 >> x2 >> x3;
    cout << "Input y-coordinates for A, B, and C: \n";
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
    
    for (source_x = -100; source_x <= 100; source_x += .01)
        {
        for (source_y = -100; source_y <= 100; source_y += .01)
            {
                accuracy_a = fabs((sqrt(((source_x - equation1_x)*(source_x - equation1_x)) + ((source_y - equation1_y)*(source_y - equation1_y))) - sqrt(((source_x - least_x)*(source_x - least_x)) + ((source_y - least_y)*(source_y - least_y))) - (distance1)));
                accuracy_b = fabs((sqrt(((source_x - equation2_x)*(source_x - equation2_x)) + ((source_y - equation2_y)*(source_y - equation2_y))) - sqrt(((source_x - least_x)*(source_x - least_x)) + ((source_y - least_y)*(source_y - least_y))) - (distance2)));
                
                if ((accuracy_a + accuracy_b) < accuracy_c)
                {
                    accuracy_c = (accuracy_a + accuracy_b);
                    real_source_x = source_x;
                    real_source_y = source_y;
                }
                
            }
        }
    cout << "Sound originates from: (" << real_source_x << "," << real_source_y << ")\n";
}
