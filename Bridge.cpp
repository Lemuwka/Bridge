#include <string>
#include <cmath>
#include "StdAfx.h"

/// \brief Class of shape
/// \details The base class is the interface for all shapes. It has the functions of area, perimeter and shape identification
class Figure
{
public:
    /// Pure virtual methods, because the class is an interface
    
    /// Square calculation
    virtual double square() const = 0;
    /// Perimeter calculation
    virtual double perimeter() const = 0;
    /// Figure name
    virtual std::string who_are_you() const = 0;
};

/// \brief Class of triangle
/// \details A class of triangular shapes. It has a constructor on three sides, an area according to Heron's formula, a perimeter and the name of the figure
class Triangle: public Figure
{
private:
    double a, b, c; /// Sides of the triangle
public:
    /// Constructor on three sides
    Triangle(double a, double b, double c): a(a), b(b), c(c) {}
    
    /// Square calculation
    virtual double square() const override
    {
        /// Heron's formula
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    
    /// Perimeter calculation
    virtual double perimeter() const override
    {
        return a + b + c;
    }
    
    /// Figure name
    virtual std::string who_are_you() const override
    {
        return "Треугольник";
    }
};

/// \brief Class of rectangle
/// \details Rectangle class. It has a constructor on two sides, an area, a perimeter and the name of the figure
class Rectangle: public Figure
{
private:
    double a, b; /// Sides of rectangle
public:
    /// Constructor on two sides
    Rectangle(double a, double b): a(a), b(b) {}
     
    /// Square calculation
    virtual double square() const override
    {
        return a * b;
    }
    
    /// Perimeter calculation
    virtual double perimeter() const override
    {
        return 2 * (a + b);
    }
    
    /// Figure name
    virtual std::string who_are_you() const override
    {
        return "Прямоугольник";
    }
};

/// \brief Class of square
/// \details A class of square shapes. It has a constructor on one side, an area, a perimeter and the name of the shape. The area and perimeter are calculated in the rectangle base class
class Square: public Rectangle
{
private:
    double a; /// Square side
public:
    /// Constructor on one sides
    Square(double a): Rectangle(a, a)  {}
    
    /// Figure name
    virtual std::string who_are_you() const override
    {
        return "Квадрат";
    }
};


/// \brief Structure for recording color in RGB format
struct RGB
{
    int r, g, b;
};

/// \brief Class of color
/// \details The base class is an interface for all colors. It has methods for displaying the name and RGB color code
class Color
{
public:
    /// Get name
    virtual std::string get_name() const = 0;
    /// Get code
    virtual RGB get_code() const = 0;
};

/// \brief Class of red color
/// \details Outputs the name "red" and the color code
class Red: public Color
{
public:
    
    /// Get name
    virtual std::string get_name() const override
    {
        return "red";
    }
    
	/// Get code
    virtual RGB get_code() const override
    {
        return RGB {255, 0, 0};
    }
};

/// \brief Class of blue color
/// \details Outputs the name "blue" and the color code
class Blue: public Color
{
public:
    /// Get name
    virtual std::string get_name() const override
    {
        return "blue";
    }
    /// Get code
    virtual RGB get_code() const override
    {
        return RGB {0, 0, 255};
    }
};


/// \brief Class of red triangle
/// \details The class is a combination of a triangle shape and a red color. Redefined methods for getting the name
class RedTriangle: public Triangle, public Red
{
public:
    RedTriangle(double a, double b, double c): Triangle(a, b, c) {}
    virtual std::string who_are_you() const override
    {
        return  Red::get_name() + " " + Triangle::who_are_you();
    }
};

/// \brief Class of red rectangle
/// \details The class is a combination of a rectangle shape and a red color. Redefined methods for getting the name
class RedRectangle: public Rectangle, public Red
{
public:
    RedRectangle(double a, double b): Rectangle(a, b) {}
    virtual std::string who_are_you() const override
    {
        return  Red::get_name() + " " + Rectangle::who_are_you();
    }
};

/// \brief Class of red square
/// \details The class is a combination of a square shape and a red color. Redefined methods for getting the name
class RedSquare: public Square, public Red
{
public:
    RedSquare(double a): Square(a) {}
    virtual std::string who_are_you() const override
    {
        return  Red::get_name() + " " + Square::who_are_you();
    }
};

/// \brief Class of blue triangle
/// \details The class is a combination of a triangle shape and a blue color. Redefined methods for getting the name
class BlueTriangle: public Triangle, public Blue
{
public:
    BlueTriangle(double a, double b, double c): Triangle(a, b, c) {}
    virtual std::string who_are_you() const override
    {
        return  Blue::get_name() + " " + Triangle::who_are_you();
    }
};

/// \brief Class of blue rectangle
/// \details The class is a combination of a rectangle shape and a blue color. Redefined methods for getting the name
class BlueRectangle: public Rectangle, public Blue
{
public:
    BlueRectangle(double a, double b): Rectangle(a, b) {}
    virtual std::string who_are_you() const override
    {
        return  Blue::get_name() + " " + Rectangle::who_are_you();
    }
};

/// \brief Class of blue square
/// \details The class is a combination of a square shape and a blue color. Redefined methods for getting the name
class BlueSquare: public Square, public Blue
{
public:
    BlueSquare(double a): Square(a) {}
    virtual std::string who_are_you() const override
    {
        return  Blue::get_name() + " " + Square::who_are_you();
    }
};

