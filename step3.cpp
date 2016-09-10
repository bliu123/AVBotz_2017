#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int arc, char** argv)
{
    ifstream input("in.txt");
    
    int x, y, z, a, b = 0, c = 0;
    while (input >> x >> y >> z)
    {
        c++;
        a = sqrt((x*x)+(y*y)+(z*z));
        if (a > 200){
            b++;
        }
        if (c == 1){
            freopen("out.txt","w",stdout);
        }
        else {
        freopen("out.txt","a",stdout);
        cout << floor(a) << "\n";
        }
    }
    freopen("out.txt","a",stdout);
    cout << b << "\n";
}
