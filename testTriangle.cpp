#include "point.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

int main() {
    // Test triangle now
    Point A(0,0), B(100,0), C(50,100);
    Triangle triangle(A, B, C);
    
    const double eps = 1e-6;  // Tolerance for floating-point comparisons
    
    // Calculate expected values
    const double sideAB = 100.0;  // Distance between A and B
    const double sideBC = std::hypot(50.0, 100.0);
    const double sideAC = sideBC;  // Triangle is isosceles
    const double expectedPerimeter = sideAB + sideBC + sideAC;
    const double expectedArea = 5000.0;
    const double expectedRadius = 62.5;  // Calculated using (a*b*c)/(4*area)

    assert(fabs(triangle.perimeter() - expectedPerimeter) < eps);
    
    assert(fabs(triangle.area() - expectedArea) < eps);
    
    // Verify center coordinates
    assert(fabs(triangle.center().x - 50.0) < eps);
    assert(fabs(triangle.center().y - 100.0/3.0) < eps); 
    
    // Verify circumscribed circle radius
    const Circle circ = triangle.circumscribedCircle();
    assert(fabs(circ.radius - expectedRadius) < eps);

    triangle.rotate(3.141592653);  // Rotate 180 degrees
    triangle.draw();
    
    std::cout << "All triangle tests passed!" << std::endl;
    return 0;
}