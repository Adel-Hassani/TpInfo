#include "point.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

//Tests passed, to push to github main branch

int main(){
    //test circle now
    Point center(0,0);
    Circle circle(100, center);
    assert(circle.circumference() == 2*3.14159265358979323846*100); // circumference
    assert(circle.area() == 3.14159265358979323846*100*100); //area
    assert(circle.center.x == 0); // x-coordinate
    assert(circle.center.y == 0); //y-coordinate
    assert(circle.equals(Circle(100, center))); //equality with another circle
    circle.draw();
}