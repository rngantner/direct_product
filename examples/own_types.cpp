/**
 * Copyright (C) 2015 Robert Gantner. All rights reserved.
 *
 * This project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this project.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <direct_product.hpp>
using namespace vectorspace;
#include <iostream>


// define some custom type
class MyClass {
    double x;
public:
    // copy ctor
    MyClass(const MyClass&) = default;
    // move ctor
    MyClass(MyClass&&) = default;
    // default ctor
    MyClass() : x(0) {}
    // ctor
    MyClass(double y) : x(y) {}
    // friends
    friend MyClass operator+(const MyClass& x, const MyClass& y);
    friend MyClass operator*(double& a, const MyClass& y);
    // getter
    double value() {return x;}
};

// Vector space operations
MyClass operator+(const MyClass& x, const MyClass& y) { return MyClass(x.x+y.x); }
MyClass operator*(double& a, const MyClass& y) { return MyClass(y.x * a); }


int main(int argc, const char *argv[])
{
    // test MyClass
    MyClass x(1.2), y(3.4);
    std::cout << "x+y: " << (x+y).value() << std::endl;

    // direct product with a double
    direct_product<double, MyClass> a(3.14, x);

    std::cout << get<0>(a) << ", "
              << get<1>(a).value() << std::endl;

    // direct product with two MyClasses
    direct_product<MyClass, MyClass> b(x, y);
    std::cout << get<0>(b).value() << ", "
              << get<1>(b).value() << std::endl;

}
