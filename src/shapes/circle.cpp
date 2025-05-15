#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <iostream>
#include "CTurtle.hpp"
#include <stdexcept> // For exceptions
namespace ct = cturtle;
const double PI = 3.14159265358979323846; // Define PI constant
 


Circle::Circle(double r, Point c) : center(c) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative!");
    }
    radius = r;
}
// Calculate circumference
double Circle::circumference() {
    return 2 * PI * radius;
}

// Calculate area
double Circle::area() {
    return PI * radius * radius;
}

// Draw the circle
void Circle::draw() {
    ct::TurtleScreen screen;
    ct::Turtle t(screen);
    
    // Hide the turtle for cleaner visualization
    t.hideturtle();
    
    // Position the turtle at the bottom of the circle (pen up)
    t.penup();
    t.setposition(center.x, center.y - radius);
    
    // Draw the circle
    t.pendown();
    t.circle(radius);
    
    // Move back to the center without drawing
    t.penup();
    t.setposition(center.x, center.y);
    
    // Keep the window open until clicked
    screen.exitonclick();
}

// Translate the circle by moving its center
void Circle::translate(Point T) {
    // Déplace le centre du cercle en ajoutant les coordonnées du point T
    center.x += T.x;
    center.y += T.y;
    
    // Affiche la confirmation du déplacement
    std::cout << "Cercle déplacé. Nouvelle position: (" 
              << center.x << ", " << center.y << ")" << std::endl;
}

// Resize the circle while maintaining its center
void Circle::resize(double ratio) {
    // Garde l'ancien rayon pour affichage
    double oldRadius = radius;
    
    // Redimensionne le rayon par le facteur donné
    radius *= ratio;
    
    // Affiche la confirmation du redimensionnement
    std::cout << "Cercle redimensionné de " << oldRadius 
              << " à " << radius << " (ratio: " << ratio << ")" << std::endl;
}

// Check if two circles are equal (same center and radius)
bool Circle::equals(Circle other) {
    // Deux cercles sont égaux si leurs centres et leurs rayons sont égaux
    bool centersEqual =  (center.x == other.center.x && center.y == other.center.y);
    bool radiiEqual = (std::abs(radius - other.radius) < 1e-10); // Comparaison de nombres à virgule flottante
    
    // Affiche le résultat de la comparaison
    if (centersEqual && radiiEqual) {
        std::cout << "Les cercles sont identiques." << std::endl;
        return true;
    } else {
        std::cout << "Les cercles sont différents." << std::endl;
        if (!centersEqual) {
            std::cout << "  - Centres différents: (" << center.x << ", " << center.y 
                      << ") vs (" << other.center.x << ", " << other.center.y << ")" << std::endl;
        }
        if (!radiiEqual) {
            std::cout << "  - Rayons différents: " << radius << " vs " << other.radius << std::endl;
        }
        return false;
    }
}
//fin circle 2