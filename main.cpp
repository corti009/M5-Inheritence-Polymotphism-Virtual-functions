#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

static constexpr double PI = 3.14159265358979323846;

class BasicShape {
private:
  double area;
  std::string name;

public:
  
  virtual void calcArea() = 0; 

  void setName(const std::string &n) { name = n; }

  void setArea(double a) { area = a; }

  std::string getName() const { return name; }

  double getArea() const { return area; }

  virtual ~BasicShape() {}
};

class Circle : public BasicShape {
private:
  double xCenter, yCenter, radius;

public:
  
  Circle(double x, double y, double r, const std::string &n = "Circle")
      : xCenter(x), yCenter(y), radius(r) {
    setName(n);
    calcArea(); 
  }

  void calcArea() override {
    double calculatedArea = PI * radius * radius;
    setArea(calculatedArea);
  }

  double getXCenter() const { return xCenter; }
  double getYCenter() const { return yCenter; }
  double getRadius() const { return radius; }
};

class Rectangle : public BasicShape {
protected:
  double length;
  double width;

public:
 
  Rectangle(double l, double w, const std::string &n = "Rectangle")
      : length(l), width(w) {
    setName(n); 
    calcArea(); 
  }

  void calcArea() override {
    double calculatedArea = length * width;
    setArea(calculatedArea); 
  }

  double getLength() const { return length; }
  double getWidth() const { return width; }
};

class Square : public Rectangle {
private:
  double side;

public:
 
  Square(double s, const std::string &n = "Square")
      
      : Rectangle(s, s, n), side(s) {
  }

  double getSide() const { return side; }
};


int main() {
  
  std::cout << std::fixed << std::setprecision(2);

  std::vector<BasicShape *> shapeArray;

  shapeArray.push_back(new Rectangle(10.0, 5.0, "Large Rectangle"));
  shapeArray.push_back(new Rectangle(4.5, 8.0, "Skinny Rectangle"));

  shapeArray.push_back(new Circle(0.0, 0.0, 3.0, "Unit Circle"));
  shapeArray.push_back(new Circle(5.0, 5.0, 7.5, "Big Circle"));

  shapeArray.push_back(new Square(6.0, "Six-by-Six Square"));

  std::cout << "--- Basic Shapes Polymorphic Calculator ---\n";
  std::cout << "-------------------------------------------\n\n";

  std::cout << "Processing " << shapeArray.size() << " shapes:\n\n";

  for (size_t i = 0; i < shapeArray.size(); ++i) {
    BasicShape *shapePtr = shapeArray[i];

    shapePtr->calcArea();

    std::cout << "Shape #" << i + 1 << ":\n";
    std::cout << "  Type: " << shapePtr->getName() << "\n";
    std::cout << "  Area: " << shapePtr->getArea() << "\n";
    std::cout << (i < shapeArray.size() - 1 ? "--------------------------\n"
                                            : "");
  }

  std::cout << "\n-------------------------------------------\n";
  std::cout << "Cleaning up memory...\n";
  for (BasicShape *shapePtr : shapeArray) {
    delete shapePtr;
  }
  std::cout << "Cleanup complete. Program finished.\n";

  return 0;
}
