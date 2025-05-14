#include "point.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;
int main(){
    Point A(0,0), C(100,100);
    Square square(A,C);
    double expected_side = 100.0;
    double tolerance = 1e-6;

    // Use of fabs in this case is for floating point comparison with error margins(tolerance)
    assert(fabs(square.side() - expected_side) < tolerance);
    assert(fabs(square.perimeter() - 4*expected_side) < tolerance);
    assert(fabs(square.area() - expected_side*expected_side) < tolerance);
    assert(square.center().x == 50);
    assert(square.center().y == 50);

    // Check inscribed circle radius
    assert(fabs(square.inscribedCircle().radius - 50.0) < tolerance);

    // Check circumscribed circle radius
    double expected_circum_radius = sqrt(100*100 + 100*100)/2;
    assert(fabs(square.circumscribedCircle().radius - expected_circum_radius) < tolerance);

    square.rotate(3.141592563/4); // Rotation 45 degrees
    square.draw();
    
    return 0;
}