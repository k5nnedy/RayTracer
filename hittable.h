#ifndef HITTABLE_H
#define HITTABLE_H

#include "utility.h"

class hit_record {

public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        //Set the hit record normal vector
        // NOTE: outward_normal is always assumed to have unit length

        front_face = dot(r.direction(), outward_normal) < 0;
        // sets normal to face against/toward ray. 
        // if our front_face is true set it to outward_normal, 
        // else we negate our outward_normal since we always want it to face towards our ray
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {

public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif