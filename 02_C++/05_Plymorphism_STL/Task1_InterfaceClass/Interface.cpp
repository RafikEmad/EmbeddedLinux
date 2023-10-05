#include<iostream>

class Drawable {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Drawable() {}   // Virtual destructor (recommended for polymorphic classes)
};

class Shape : public Drawable {
public:
    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout<<"Draw Circle"<<std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout<<"Draw Square"<<std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout<<"Draw Rectangle"<<std::endl;
    }
};

int main() {
    Circle circle;
    Square square;
    Rectangle rectangle;
    Drawable* shapes[] = {&circle, &square, &rectangle};

    for (Drawable* shape : shapes) {
        shape->draw();
    }

    return 0;
}
