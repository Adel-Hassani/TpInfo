#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <vector>
#include "shapes.hpp"
#include "draw.hpp"

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {};
double module(Point a ,Point b )
{
    // calcule le module entre deux points a travers un vecteur
    Point c;
    c.x=b.x-a.x;
    c.y=b.y-a.y;
    return sqrt(c.x*c.x+c.y*c.y);
}
double Triangle::perimeter()
{
    return module(A,B)+module(B,C)+module(C,A);
}
void Triangle::draw()
{
    std::vector<Point> points = {
        A,
        B,
        C,
        A
    };
    draw_picture(points);
}
void Triangle::resize(double ratio)
{
    A.x=A.x*ratio;
    A.y=A.y*ratio;
    B.x=B.x*ratio;
    B.y=B.y*ratio;
    C.x=C.x*ratio;
    C.y=C.y*ratio;
}
void Triangle::rotate(double angle) {
    Point Center = center();
    
    double aX = A.x - Center.x;
    double aY = A.y - Center.y;
    double bX = B.x - Center.x;
    double bY = B.y - Center.y;
    double cX = C.x - Center.x;
    double cY = C.y - Center.y;
    //we do this to ensure the rotation is around the center
    A.x = aX * cos(angle) - aY * sin(angle) + Center.x;
    A.y = aX * sin(angle) + aY * cos(angle) + Center.y;
    
    B.x = bX * cos(angle) - bY * sin(angle) + Center.x;
    B.y = bX * sin(angle) + bY * cos(angle) + Center.y;
    
    C.x = cX * cos(angle) - cY * sin(angle) + Center.x;
    C.y = cX * sin(angle) + cY * cos(angle) + Center.y;
}
bool Triangle::equals(Triangle triangle)
{
    // Compare coordinates directly since Point class doesn't have == operator
    if(triangle.A.x == A.x && triangle.A.y == A.y && 
       triangle.B.x == B.x && triangle.B.y == B.y && 
       triangle.C.x == C.x && triangle.C.y == C.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Triangle::isRightAngled()
{
    if(module(A,B)*module(A,B)==module(B,C)*module(B,C)+module(C,A)*module(C,A))
    {
        return true;
    }
    if(module(A,B)*module(A,B)+module(B,C)*module(B,C)==module(C,A)*module(C,A))
    {
        return true;
    }
    if(module(A,B)*module(A,B)+module(C,A)*module(C,A)==module(B,C)*module(B,C))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Triangle::area() {
    double area = 0.5 * ( A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y) );
    if (area < 0) {
        area = -area;
    }
    return area;
}


Point Triangle::center() {
    double x_centre = (A.x + B.x + C.x) / 3.0;
    double y_centre = (A.y + B.y + C.y) / 3.0;
    return Point(x_centre, y_centre);
}


void Triangle::translate(Point T) {
    A.x = A.x + T.x;
    A.y = A.y + T.y;
    B.x = B.x + T.x;
    B.y = B.y + T.y;
    C.x = C.x + T.x;
    C.y = C.y + T.y;
}



bool Triangle::isEquilateral() {
    double ab = module(A, B);
    double bc = module(B, C);
    double ca = module(C, A);

    double aproximation = 1e-6; //marge d erreur de calcul

    return (ab - bc < aproximation && ab - bc > -aproximation) &&
           (bc - ca < aproximation && bc - ca > -aproximation) &&
           (ca - ab < aproximation && ca - ab > -aproximation);
}

bool Triangle::isIsoceles() {
    double ab = module(A, B);
    double bc = module(B, C);
    double ca = module(C, A);

    double aproximation = 1e-6; //marge d erreur de calcul

    return (ab - bc < aproximation && ab - bc > -aproximation) ||
           (bc - ca < aproximation && bc - ca > -aproximation) ||
           (ca - ab < aproximation && ca - ab > -aproximation);
}

Circle Triangle::circumscribedCircle() {
    double ab = module(A, B);
    double bc = module(B, C);
    double ca = module(C, A);

    double area = this->area();

    double R = (ab * bc * ca) / (4.0 * area);

    double x_center = (ab * A.x + bc * B.x + ca * C.x) / (ab + bc + ca);
    double y_center = (ab * A.y + bc * B.y + ca * C.y) / (ab + bc + ca);

    Point center(x_center, y_center);
    return Circle(R, center); 
}