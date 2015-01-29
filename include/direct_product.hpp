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

#include <stdlib.h>     // size_t
#include <type_traits>  // std::enable_if
#include <utility>      // std::move

#ifndef DIRECT_PRODUCT_HPP
#define DIRECT_PRODUCT_HPP
#pragma once

template<class... Ts> struct direct_product {};

/**
 * Variadic template to store the components of the direct product.
 */
template<class T, class... Ts>
struct direct_product<T, Ts...> : direct_product<Ts...> {
    // copy ctor
    direct_product(const direct_product<T, Ts...>&) = default;
    // copy prepend
    direct_product(T t, const direct_product<Ts...>& p) : direct_product<Ts...>(p), component(t) {}
    // move ctor
    direct_product(direct_product<T, Ts...>&&) = default;
    // move prepend
    direct_product(T t, direct_product<Ts...>&& p) : direct_product<Ts...>(p), component(t) {}
    // default ctor
    direct_product(T t, Ts... ts) : direct_product<Ts...>(ts...), component(t) {}
    // data
    T component;
};

// prepend: move version
template<class T, class... Ts>
direct_product<T, Ts...> prepend(T t, direct_product<Ts...>&& p) {
    return direct_product<T, Ts...>(t, std::move(p));
}
// prepend: copy version
template<class T, class... Ts>
direct_product<T, Ts...> prepend(T t, const direct_product<Ts...>& p) {
    return direct_product<T, Ts...>(t, p);
}

/**
 * type of k-th element
 */
template<size_t k, class T, class... Ts>
struct component_type {};
// k=0 (stop recursion)
template<class T, class... Ts>
struct component_type<0, direct_product<T, Ts...>> { typedef T type; };
// recurse
template<size_t k, class T, class... Ts>
struct component_type<k, direct_product<T, Ts...>> {
    typedef typename component_type<k-1, direct_product<Ts...>>::type type;
};

/**
 * get the k-th component
 */
template<size_t k, class... Ts>
typename std::enable_if<k==0, typename component_type<0, direct_product<Ts...>>::type&>::type
get(direct_product<Ts...>& t) {
    return t.component;
}
// recurse
template<size_t k, class T, class... Ts>
typename std::enable_if<k!=0, typename component_type<k, direct_product<T,Ts...>>::type&>::type
get(direct_product<T, Ts...>& t) {
    direct_product<Ts...>& base = t; // TODO: why does this work??
    return get<k-1>(base);
}

/**
 * Addition of two instances: x+y
 */
// recursion
template<class T, class... Ts> direct_product<T,Ts...>
operator+(const direct_product<T,Ts...>& x, const direct_product<T,Ts...>& y) {
    const direct_product<Ts...>& base_x = x;
    const direct_product<Ts...>& base_y = y;
    // use prepend constructor
    return direct_product<T, Ts...>(x.component+y.component, base_x+base_y);
}
// base case
template<class... Ts> direct_product<>
operator+(const direct_product<Ts...>& x, const direct_product<Ts...>& y) {
    return direct_product<Ts...>();
}
/**
 * Multiplication by a scalar (type S): a*x
 */
// recursion
template<class S, class T, class... Ts>
direct_product<T,Ts...>
operator*(S& a, direct_product<T,Ts...>& x) {
    direct_product<Ts...>& base = x;
    return direct_product<T, Ts...>(a*x.component, a*base);
}
// base case
template<class S, class... Ts> direct_product<>
operator*(S& a, direct_product<Ts...>& x) {
    return direct_product<Ts...>();
}
///// rvalue reference overload
// recursion
template<class S, class T, class... Ts>
direct_product<T,Ts...>
operator*(S&& a, direct_product<T,Ts...>& x) {
    direct_product<Ts...>& base = x;
    return direct_product<T, Ts...>(a*x.component, a*base);
}
// base case
template<class S, class... Ts> direct_product<>
operator*(S&& a, direct_product<Ts...>& x) {
    return direct_product<Ts...>();
}



#endif /* end of include guard: DIRECT_PRODUCT_HPP */

