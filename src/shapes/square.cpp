#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include "shapes.hpp"
#include <cmath>

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side() {
    return A.distance(C) / sqrt(2);
}
double Square::perimeter() {
    return 4 * side();
}
double Square::area() {
    return side() * side();
}
Point Square::center() {
    return Point((A.x + C.x) / 2, (A.y + C.y) / 2);
}
void Square::draw() {
    Point O = center();
    double dx = A.x - O.x;
    double dy = A.y - O.y;

    Point B(O.x + dy, O.y - dx);
    Point D(O.x - dy, O.y + dx);

    draw_picture({A, B, C, D, A});
}
void Square::translate(Point T) {
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
}
void Square::resize(double ratio) {
    double new_side = side() * ratio;
    double center_x = center().x;
    double center_y = center().y;

    A.x = center_x - new_side / 2;
    A.y = center_y - new_side / 2;
    C.x = center_x + new_side / 2;
    C.y = center_y + new_side / 2;
}
void Square::rotate(double angle) {
    Point center_point = center();
    
    // Rotate point A around the center(fixed from last faulty implementation)
    double dx = A.x - center_point.x;
    double dy = A.y - center_point.y;
    A.x = center_point.x + dx * cos(angle) - dy * sin(angle);
    A.y = center_point.y + dx * sin(angle) + dy * cos(angle);
    
    // Rotate point C around the center(fixed as well after bad tests)
    dx = C.x - center_point.x;
    dy = C.y - center_point.y;
    C.x = center_point.x + dx * cos(angle) - dy * sin(angle);
    C.y = center_point.y + dx * sin(angle) + dy * cos(angle);
}
bool Square::equals(Square square) {
    return (A.x == square.A.x && A.y == square.A.y && C.x == square.C.x && C.y == square.C.y);
}
Circle Square::inscribedCircle() {
    double radius = side() / 2;
    
    Point center_point = center();
    
    return Circle(radius, center_point);
}

Circle Square::circumscribedCircle() {
    double radius = A.distance(C) / 2;
    return Circle(radius, center());
}