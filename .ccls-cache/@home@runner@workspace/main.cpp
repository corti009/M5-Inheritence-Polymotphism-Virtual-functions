#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

class Shape {
public:
   
    virtual double calculateArea() const = 0;

    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() = default;

    virtual std::string getName() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
  
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }
    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }

    std::string getName() const override {
        return "Circle";
    }
};


class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    
    Rectangle(double l, double w) : length(l), width(w) {}
    double getLength() const { return length; }
    double getWidth() const { return width; }
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }

    std::string getName() const override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    
    double base;
    double height;
    double sideA;
    double sideB;
    double sideC;

public:
    
    Triangle(double b, double h, double a, double c) 
        : base(b), height(h), sideA(a), sideB(b), sideC(c) 
    {}

    Triangle(double b, double h, double a, double c, double d)
        : base(b), height(h), sideA(c), sideB(d), sideC(a) 
    {}

Triangle(double side1, double side2, double side3)
    : base(side1), height(0.0), sideA(side1), sideB(side2), sideC(side3)
{}

  
    double getBase() const { return base; }
    double getHeight() const { return height; }
    double getSideA() const { return sideA; }
    double getSideB() const { return sideB; }
    double getSideC() const { return sideC; }
    double calculateArea() const override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() const override {

        return sideA + sideB + sideC;
    }

    std::string getName() const override {
        return "Triangle";
    }
};

void displayShapeInfo(const Shape* shape) {
    if (!shape) return;
  
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n--- " << shape->getName() << " Calculations ---\n";

    if (auto circle = dynamic_cast<const Circle*>(shape)) {
        std::cout << "  Radius: " << circle->getRadius() << "\n";
    } 
   
    else if (auto rect = dynamic_cast<const Rectangle*>(shape)) {
        std::cout << "  Length: " << rect->getLength() << "\n";
        std::cout << "  Width: " << rect->getWidth() << "\n";
    }
    
    else if (auto tri = dynamic_cast<const Triangle*>(shape)) {
        std::cout << "  Sides: " << tri->getSideA() << ", " << tri->getSideB() << ", " << tri->getSideC() << "\n";
        std::cout << "  (Used Base: " << tri->getBase() << ", Height: " << tri->getHeight() << " for Area)\n";
    }

    std::cout << "  Area: " << shape->calculateArea() << "\n";
    std::cout << "  Perimeter: " << shape->calculatePerimeter() << "\n";
    std::cout << "------------------------------------------\n";
}

int main() {
    std::cout << "--- Basic Geometric Shapes Polymorphism Demonstration ---\n";

    Shape* myCircle = new Circle(5.0);

    Shape* myRectangle = new Rectangle(10.0, 6.0);

    Shape* myTriangle = new Triangle(3.0, 4.0, 4.0, 5.0);

    std::vector<Shape*> shapes;
    shapes.push_back(myCircle);
    shapes.push_back(myRectangle);
    shapes.push_back(myTriangle);

    for (const auto& shape : shapes) {
        displayShapeInfo(shape);
    }

    for (const auto& shape : shapes) {
        delete shape;
    }

    std::cout << "\nDemonstration complete. Memory cleaned up.\n";

    return 0;
}