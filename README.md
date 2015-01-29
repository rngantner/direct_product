# direct_product
Represents direct product of types fulfilling the VectorSpace concept, and implements addition and scalar multiplication for the resulting type.

The types involved must model the VectorSpace concept, defined as follows:

## VectorSpace
The goal of this concept is to provide minimal requirements for classes whose instances represent elements of a vector space.
The two basic requirements are an addition operation and multiplication with a scalar;
in C++ we assume these to be given by `operator+` and `operator*`, respectively.

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

