#include <iostream>
#include "../inc/Point.hpp"

int main() {

    // Define the vertices of the triangle
    Point a(10, 0);
    Point b(0, 0);
    Point c(10, 10);

    // Define some points to test if they are inside the triangle
    Point insidePoint(5.01f, 5); // Point inside the triangle
    Point outsidePoint(4.99f, 5); // Point outside the triangle
    Point onEdgePoint(5, 5);  // Point on the edge of the triangle

    // Test with the point inside
    if (bsp(a, b, c, insidePoint)) {
        std::cout << "\033[32mPoint is inside the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    // Test with the point outside
    if (bsp(a, b, c, outsidePoint)) {
        std::cout << "\033[32mPoint is inside the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    // Test with the point on the edge
    if (bsp(a, b, c, onEdgePoint)) {
        std::cout << "\033[33mPoint is on the edge of the triangle." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mPoint is NOT inside the triangle." << "\033[0m" << std::endl;
    }

    return 0;
}
