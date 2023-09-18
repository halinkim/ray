#ifndef VEC
#define VEC
#include <cmath>
class vec {
public:
    double v[3]{};

    vec();
    vec(double v1, double v2, double v3);

    double x();
    double y();
    double z();

    vec operator-();
    double operator[](int i);
    vec& operator+=(vec w);
    vec& operator*=(double t);
    vec& operator/=(double t);
    double len();
    double lensq();
};

vec::vec() : vec(0, 0, 0) { };

vec::vec(double v1, double v2, double v3) {
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
}

double vec::x() {
    return v[0];
}

double vec::y() {
    return v[1];
}

double vec::z() {
    return v[2];
}

vec vec::operator-() {
    return {-v[0], -v[1], -v[2]};
}

double vec::operator[](int i) {
    return v[i];
}

vec &vec::operator+=(vec w) {
    for (int i = 0; i < 3; ++i) {
        v[i] += w[i];
    }
    return *this;
}

vec &vec::operator*=(double t) {
    for (int i = 0; i < 3; ++i) {
        v[i] *= t;
    }
    return *this;
}

vec &vec::operator/=(double t) {
    return *this *= 1 / t;
}

double vec::len() {
    return std::sqrt(lensq());
}

double vec::lensq() {
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

inline vec operator+(const vec &u, const vec &w) {
    return {u.v[0] + w.v[0], u.v[1] + w.v[1], u.v[2] + w.v[2]};
}

inline vec operator-(const vec &u, const vec &w) {
    return {u.v[0] - w.v[0], u.v[1] - w.v[1], u.v[2] - w.v[2]};
}

inline vec operator*(const vec &u, const vec &w) {
    return {u.v[0] * w.v[0], u.v[1] * w.v[1], u.v[2] * w.v[2]};
}

inline vec operator*(double t, const vec &w) {
    return {t*w.v[0], t*w.v[1], t*w.v[2]};
}

inline vec operator*(const vec &w, double t) {
    return t * w;
}

inline vec operator/(vec w, double t) {
    return (1/t) * w;
}

inline double dot(const vec &u, const vec &w) {
    return u.v[0] * w.v[0]
           + u.v[1] * w.v[1]
           + u.v[2] * w.v[2];
}

inline vec cross(const vec &u, const vec &w) {
    return {u.v[1] * w.v[2] - u.v[2] * w.v[1],
                u.v[2] * w.v[0] - u.v[0] * w.v[2],
                u.v[0] * w.v[1] - u.v[1] * w.v[0]};
}

inline vec unit_vector(vec w) {
    return w / w.len();
}
#endif