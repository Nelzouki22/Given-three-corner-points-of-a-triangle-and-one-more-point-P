#include <iostream>

// Structure to represent a point
struct Point {
    double x, y;
};

// Function to calculate the area of a triangle given its vertices
double triangleArea(Point A, Point B, Point C) {
    return std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

// Function to check if point P lies within the triangle formed by points A, B, and C
bool isPointInTriangle(Point A, Point B, Point C, Point P) {
    // Calculate area of the triangle ABC
    double ABC = triangleArea(A, B, C);

    // Calculate area of the triangle PAB
    double PAB = triangleArea(P, A, B);

    // Calculate area of the triangle PBC
    double PBC = triangleArea(P, B, C);

    // Calculate area of the triangle PCA
    double PCA = triangleArea(P, C, A);

    // Check if sum of PAB, PBC and PCA is same as ABC
    return (ABC == PAB + PBC + PCA);
}

int main() {
    Point A, B, C, P;

    // Input coordinates of the triangle vertices
    std::cout << "Enter coordinates of point A (x y): ";
    std::cin >> A.x >> A.y;

    std::cout << "Enter coordinates of point B (x y): ";
    std::cin >> B.x >> B.y;

    std::cout << "Enter coordinates of point C (x y): ";
    std::cin >> C.x >> C.y;

    // Input coordinates of point P
    std::cout << "Enter coordinates of point P (x y): ";
    std::cin >> P.x >> P.y;

    // Check if point P lies within the triangle ABC
    if (isPointInTriangle(A, B, C, P)) {
        std::cout << "Point P lies within the triangle." << std::endl;
    }
    else {
        std::cout << "Point P does not lie within the triangle." << std::endl;
    }

    return 0;
}
