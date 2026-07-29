#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        double e[3]; //array of 3 doubles

        vec3(): e{0, 0, 0} {} //default constructor
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} //constructor with parameters

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // Operator overloaders:
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[] (int i ) const { return e[i]; }
        double& operator[] (int i ) { return e[i]; }

        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        // Vector length functions
        double length() const {
            return std::sqrt(length_squared());
        }
        double length_squared() const {
            return e[0]*e[0] + e[1] * e[1] + e[2] * e[2];
        }
};

// point3 is an alias for vec3 to make code easier to read
using point3 = vec3;

//Vector Utility Functions:
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3 v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2] );
}

inline vec3 operator-(const vec3& u, const vec3 v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2] );
}


inline vec3 operator*(double t, const vec3& v) {// multiplication for scalar comes before vector
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {// multiplication for scalar comes after vector
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

//cross-product func of 2 3-Dimensional vectors
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3( 
        u.e[1] * v.e[2] - u.e[2] * v.e[1], // i
        u.e[0] * v.e[2] - u.e[2] * v.e[0], // j
        u.e[0] * v.e[2] - u.e[2] * v.e[0]  // k
    );
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}
#endif