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


int main(int argc, const char *argv[])
{
    direct_product<double, int, char> a(3.4, 2, 'a');

    std::cout << get<0>(a) << ", "
              << get<1>(a) << ", "
              << get<2>(a) << std::endl;

    std::cout << "-------" << std::endl;

    auto b1 = prepend((long) 423, a);
    auto b2 = prepend((long) 241, a);

    std::cout << get<0>(b1) << ", "
              << get<1>(b1) << ", "
              << get<2>(b1) << ", "
              << get<3>(b1) << std::endl;

    std::cout << "-------" << std::endl;

    auto c1 = prepend((long) 423, std::move(a));
    auto c2 = prepend((long) 241, std::move(a));

    std::cout << get<0>(c1) << ", "
              << get<1>(c1) << ", "
              << get<2>(c1) << ", "
              << get<3>(c1) << std::endl;

    std::cout << "-------" << std::endl;

    auto d = b1+b2;

    std::cout << get<0>(d) << ", "
              << get<1>(d) << ", "
              << get<2>(d) << ", "
              << get<3>(d) << std::endl;

    std::cout << "-------" << std::endl;

    auto e = 3*b2;

    std::cout << get<0>(e) << ", "
              << get<1>(e) << ", "
              << get<2>(e) << ", "
              << get<3>(e) << std::endl;

    return 0;
}
