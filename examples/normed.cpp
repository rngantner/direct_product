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
#include <type_traits> // is_scalar

// norm for scalar types
template<class T>
typename std::enable_if<std::is_scalar<T>::value, double>::type
norm(T x) { return std::sqrt(x*x); }

//// define L^2 norm
//double norm(direct_product<double, double>& x) {
//    //return norm(get<0>(x)) + norm(get<1>(x));
//    return std::pow<double>(std::pow<double>(get<0>(x),2) + std::pow<double>(get<1>(x),2), 1./2);
//}

int main(int argc, const char *argv[])
{
    double a = -2;
    std::cout << "norm(a)=" << norm(a) << std::endl;;
    double b = 7;
    std::cout << "norm(b)=" << norm(b) << std::endl;;
    double c = -10;
    std::cout << "norm(b)=" << norm(c) << std::endl;;

    direct_product<double, double, double> d(a,b,c);

    // define norm to be L2 norm
    auto norm = [](direct_product<double, double, double> x){ return norm_p(x,2); };

    std::cout << get<0>(d) << ", "
              << get<1>(d) << ", "
              << get<2>(d) << std::endl;

    std::cout << "norm(c)=" << norm(d) << std::endl;;

    return 0;
}
