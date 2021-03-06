#include "camera.h"
#include <qgl.h>

void OrbitCamera::mouseMove(const Vector2 &delta)
{
    // Rotate the eye vector around the origin
    theta += delta.x * 0.01f;
    phi += delta.y * 0.01f;

    // Keep theta in [0, 2pi] and phi in [-pi/2, pi/2]
    theta -= floorf(theta / M_2PI) * M_2PI;
    phi = max(0.01f - M_PI / 2, min(M_PI / 2 - 0.01f, phi));
}

void OrbitCamera::mouseWheel(float delta)
{
    zoom *= powf(0.999f, delta);
    if (zoom > 20) {
       zoom = 20;
   }
}


Vector3 OrbitCamera::getCameraPosition() {
    float x = cos(theta) * cos(phi);
    float y = sin(phi);
    float z = sin(theta) * cos(phi);

    return zoom * Vector3(x,y,z);
}
