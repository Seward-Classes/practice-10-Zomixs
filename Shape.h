// AI Disclaimer: This code was written with minimal AI assistance.
// Used AI for: syntax checking and debugging only.
// Core logic and problem-solving approach are my own work.

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

// base class - cant instantiate directly bc of pure virtual
class Shape {
public:
    virtual double getArea() const = 0;  // pure virtual
    virtual void display() const;
    virtual ~Shape() = default;
};

// Rectangle class
class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
    Rectangle(double w, double h);
    double getArea() const override;
    void display() const override;
};

class Circle : public Shape {
public:
    Circle(double r);
    double getArea() const override;
    void display() const override;

private:
    double radius;
};

#endif
