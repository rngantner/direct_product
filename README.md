# direct_product
C++ library representing the direct product of types fulfilling the VectorSpace concept (see below).
The resulting type again models VectorSpace (i.e. addition of two instances and multiplication by a scalar are implemented).

All types involved must model the VectorSpace concept, defined as follows:

## VectorSpace
The goal of this concept is to provide minimal requirements for classes whose instances represent elements of a vector space. The two basic requirements are an addition operation and multiplication with a scalar; in C++ we assume these to be given by `operator+` and `operator*`, respectively.

### Requirements

The type `V` satisfies `VectorSpace` if
  * the type satisfies `CopyConstructible`

and, given
  * `v,w`, two instances of `V`,
  * `a`, an instance of a scalar type,

the following expressions must be valid and have their specified effects.

 Expression  | Postcondition
------------ | -----------------
 `V u = v+w` | `u` contains the sum of `v` and `w`
 `V u = a*w` | `u` contains the product of `a` and `v`

### Notes

Only multiplication by a scalar from the left is assumed in the expressions above;
the reverse argument ordering (i.e. `w*a`) is not required.

## NormedVectorSpace
In certain applications, norms of elements are required; this concept extends `VectorSpace` by requiring that there exists a `norm(x)` function for any instance `x` of a class modelling VectorSpace.

### Requirements

The type `V` satisfies `NormedVectorSpace` if
  * the type satisfies `VectorSpace`

and, given
  * `v`, an instance of `V`,

the following expressions must be valid and have their specified effects.

 Expression  | Postcondition
------------ | -----------------
 `double n = norm(v)` | `n` contains the norm of `v`
 
