#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Ray.h"

class Camera {

private:
    
    Vec3  m_origin;
    Vec3  m_lower_left_corner;
    Vec3  m_horizontal;
    Vec3  m_vertical;

    Vec3  m_u;
    Vec3  m_v;
    Vec3  m_w;    
    float m_lens_radius;

public:

    explicit Camera(const Vec3& origin, 
                    const Vec3& lower_left_corner,
                    const Vec3& horizontal,
                    const Vec3& vertical);
    explicit Camera(const Vec3& origin,
                    const Vec3& lookat,
                    const Vec3& up,
                    float fov, float aspect,
                    float aperture = 0.0f, float focus_distance = 1.0f);
    ~Camera() {};

    Ray GetRay(float s, float t) const;
};
#endif