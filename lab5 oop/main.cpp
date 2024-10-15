// 1. Create an abstract class Figure with methods for calculating the area and perimeter,
//  as well as a method for displaying information about the figure on the screen.
// 2. Create derived classes: Rectangle, Circle, and Triangle with their own methods for calculating area and perimeter.
// 3. Create an array of n figures and display complete information about all figures on the screen.


#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class Point {
    double x, y;
public:
    Point(double x1, double y1) {
        this->x = x1;
        this->y = y1;
    }
    void set_x(double x1) { this->x = x1; };
    void set_y(double y1) { this->y = y1; };
    void set_xy(double x1, double y1) {
        this->set_x(x1);
        this->set_y(y1);
    };
    double get_x() { return this->x; };
    double get_y() { return this->y; };
};

class Figure {
    Point center;
public:
    Figure(Point t) : center(t) {};
    virtual double perimetr() = 0;
    virtual double area() = 0;
    virtual void print_info() = 0;
    virtual ~Figure() {};
};

class RRectangle : public Figure {
    Point p1, p2; // Diagonal points
public:
    RRectangle(Point a, Point b, Point center) : Figure(center), p1(a), p2(b) {};
    double perimetr();
    double area();
    void print_info();
};

class Triangle : public Figure {
    Point p1, p2, p3; // Triangle vertices
public:
    Triangle(Point a, Point b, Point c, Point center) : Figure(center), p1(a), p2(b), p3(c) {};
    double perimetr();
    double area();
    void print_info();
};

class Circle : public Figure {
    double radius;
public:
    Circle(double r, Point center) : Figure(center), radius(r) {};
    double perimetr();
    double area();
    void print_info();
};

double point_distance(Point a, Point b) {
    double x = b.get_x() - a.get_x();
    double y = b.get_y() - a.get_y();
    return sqrt(x * x + y * y);
}

double RRectangle::perimetr() {
    Point temp(this->p1.get_x(), this->p2.get_y());
    return 2 * (point_distance(this->p1, temp) + point_distance(temp, this->p2));
};
double RRectangle::area() {
    Point temp(this->p1.get_x(), this->p2.get_y());
    return point_distance(this->p1, temp) * point_distance(temp, this->p2);
};
void RRectangle::print_info() {
    std::cout << "\nRectangle Information: " << std::endl;
    std::cout << "Perimeter = " << this->perimetr() << std::endl;
    std::cout << "Area = " << this->area() << std::endl << std::endl;
};

double Triangle::perimetr() {
    return point_distance(p1, p2) + point_distance(p2, p3) + point_distance(p1, p3);
};
double Triangle::area() {
    double a = point_distance(p1, p2);
    double b = point_distance(p2, p3);
    double c = point_distance(p1, p3);
    double p = 0.5 * (a + b + c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
};
void Triangle::print_info() {
    std::cout << "\nTriangle Information: " << std::endl;
    std::cout << "Perimeter = " << this->perimetr() << std::endl;
    std::cout << "Area = " << this->area() << std::endl << std::endl;
};

double Circle::perimetr() {
    return 2 * radius * M_PI;
};
double Circle::area() {
    return M_PI * radius * radius;
};
void Circle::print_info() {
    std::cout << "\nCircle Information: " << std::endl;
    std::cout << "Radius = " << this->radius << std::endl;
    std::cout << "Perimeter = " << this->perimetr() << std::endl;
    std::cout << "Area = " << this->area() << std::endl << std::endl;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);// Enable Russian language output
    char temp_type;
    double x1, x2, x3, y1, y2, y3, y4, x4;
    int n;
    cout << "Enter the number of shapes: ";
    cin >> n;
    Figure* arr[n];
    int i = 0;
    while (i < n) {
        cout << "Select the shape type (1-rectangle, 2-circle, 3-triangle): ";
        cin >> temp_type;

        switch (temp_type) {
            case '1':
                cout << "Enter center coordinates: ";
                cin >> x1 >> y1;
                cout << "Enter p1 coordinates: ";
                cin >> x2 >> y2;
                cout << "Enter p2 coordinates: ";
                cin >> x3 >> y3;
                arr[i] = new RRectangle(Point(x2, y2), Point(x3, y3), Point(x1, y1));
                i++;
                break;
            case '2':
                cout << "Enter center coordinates: ";
                cin >> x1 >> y1;
                cout << "Enter radius: ";
                cin >> x2;
                arr[i] = new Circle(x2, Point(x1, y1));
                i++;
                break;
            case '3':
                cout << "Enter center coordinates: ";
                cin >> x1 >> y1;
                cout << "Enter p1 coordinates: ";
                cin >> x2 >> y2;
                cout << "Enter p2 coordinates: ";
                cin >> x3 >> y3;
                cout << "Enter p3 coordinates: ";
                cin >> x4 >> y4;
                arr[i] = new Triangle(Point(x2, y2), Point(x3, y3), Point(x4, y4), Point(x1, y1));
                i++;
                break;
            default:
                cout << "\nInvalid shape type." << endl;
                break;
        }
    }
    for (i = 0; i < n; i++) {
        arr[i]->print_info();
        delete arr[i];
    }
    return 0;
}