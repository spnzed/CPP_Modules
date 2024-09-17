#include <iostream>
#include "../inc/Point.hpp"

int main() {
    // Define the vertices of the triangle
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    // Define some points to test if they are inside the triangle
    Point insidePoint(2, 2); // Point inside the triangle
    Point outsidePoint(5, 5); // Point outside the triangle
    Point onEdgePoint(0, 2);  // Point on the edge of the triangle

    // Test with the point inside
    if (bsp(a, b, c, insidePoint)) {
        std::cout << "\033[32mPoint (2, 2) is inside the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint (2, 2) is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    // Test with the point outside
    if (bsp(a, b, c, outsidePoint)) {
        std::cout << "\033[32mPoint (5, 5) is inside the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint (5, 5) is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    // Test with the point on the edge
    if (bsp(a, b, c, onEdgePoint)) {
        std::cout << "\033[33mPoint (0, 2) is on the edge of the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint (0, 2) is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    return 0;
}
