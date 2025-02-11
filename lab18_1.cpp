#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
    double left, right;
    if (R1.x > R2.x) left = R1.x;
    else left = R2.x;

    if (R1.x + R1.w < R2.x + R2.w) right = R1.x + R1.w;
    else right = R2.x + R2.w;

    double overlap_width = right - left;

    double top, bottom;
    if (R1.y < R2.y) top = R1.y;
    else top = R2.y;

    if (R1.y - R1.h > R2.y - R2.h) bottom = R1.y - R1.h;
    else bottom = R2.y - R2.h;

    double overlap_height = top - bottom;

    if (overlap_width <= 0 || overlap_height <= 0) return 0;
    
    return overlap_width * overlap_height;
}

int main() {
    Rect R1 = {1,1,5,5};
    Rect R2 = {2,2,5,5};
    cout << overlap(R1, R2);

    return 0;
}
