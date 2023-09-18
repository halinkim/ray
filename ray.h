//
// Created by halin on 2023-09-18.
//

#ifndef RAY_RAY_H
#define RAY_RAY_H

#include "vec.h"
class ray {
public:
    vec ori;
    vec dir;

    ray(vec origin, vec dir);

    vec origin();
    vec direction();
    vec paramt(double t);
};

ray::ray(vec origin_, vec dir_) {
    ori = vec(origin_);
    dir = vec(dir_);
}

vec ray::origin() {
    return ori;
}

vec ray::direction() {
    return dir;
}

vec ray::paramt(double t) {
    return ori + t * dir;
}

#endif //RAY_RAY_H
