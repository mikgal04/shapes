#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>



class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
    virtual void showInfo() const = 0;
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double getArea() const override {
        return 0.5 * base * height;
    }

    double getVolume() const override {
        return 0.0;
    }

    void showInfo() const override {
        std::cout << "Треугольник: " << std::endl;
        std::cout << "Основание: " << base << std::endl;
        std::cout << "Высота: " << height << std::endl;
        std::cout << "Площадь: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double getArea() const override {
        return side * side;
    }

    double getVolume() const override {
        return 0.0;
    }

    void showInfo() const override {
        std::cout << "Квадрат: " << std::endl;
        std::cout << "Сторона: " << side << std::endl;
        std::cout << "Площадь: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getVolume() const override {
        return 0.0;
    }

    void showInfo() const override {
        std::cout << "Круг: " << std::endl;
        std::cout << "Радиус: " << radius << std::endl;
        std::cout << "Площадь: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

class Pyramid : public Shape {
private:
    double base;
    double height;

public:
    Pyramid(double base, double height) : base(base), height(height) {}

    double getArea() const override {
        return base * base + 2 * base * sqrt((height * height) - ((base * base) / 4));
    }

    double getVolume() const override {
        return (base * base * height) / 3;
    }

    void showInfo() const override {
        std::cout << "Пирамида: " << std::endl;
        std::cout << "Основание: " << base << std::endl;
        std::cout << "Высота: " << height << std::endl;
        std::cout << "Площадь: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getArea() const override {
        return 2 * 3.14159 * radius * (radius + height);
    }

    double getVolume() const override {
        return 3.14159 * radius * radius * height;
    }

    void showInfo() const override {
        std::cout << "Цилиндр: " << std::endl;
        std::cout << "Радиус: " << radius << std::endl;
        std::cout << "Высота: " << height << std::endl;
        std::cout << "Площадь: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

class Sphere : public Shape {
private:
    double radius;

public:
    Sphere(double radius) : radius(radius) {}

    double getArea() const override {
        return 4.0 * 3.14159 * radius * radius;
    }

    double getVolume() const override {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }

    void showInfo() const override {
        std::cout << "Сфера: " << std::endl;
        std::cout << "Радиус: " << radius << std::endl;
        std::cout << "Площадь поверхности: " << getArea() << std::endl;
        std::cout << "Объем: " << getVolume() << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;

    Triangle triangle(4, 6);
    shapes.push_back(&triangle);

    Square square(5);
    shapes.push_back(&square);

    Circle circle(3);
    shapes.push_back(&circle);

    Pyramid pyramid(8, 10);
    shapes.push_back(&pyramid);

    Cylinder cylinder(2, 7);
    shapes.push_back(&cylinder);


    for (const auto& shape : shapes) {
        shape->showInfo();
        std::cout << std::endl;
    }

    return 0;
}

