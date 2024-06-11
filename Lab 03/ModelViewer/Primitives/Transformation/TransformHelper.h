//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_TRANSFORMHELPER_H
#define MODELVIEWER_TRANSFORMHELPER_H


#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/vec_operations.hpp>
#include <boost/qvm/map_mat_vec.hpp>

using Point3dForm = glm::vec<3, double>;
using Point4dForm = glm::vec<4, double>;
using applyTransformForm = glm::mat<4, 4, double, glm::defaultp>;

class TransformHelper {
public:
    static applyTransformForm translate(const applyTransformForm& mat, const Point3dForm& offset);

    static double radians(double degrees);

    static applyTransformForm rotate(const applyTransformForm& mat, double rad, const Point3dForm& offset);

    static applyTransformForm rotate(const applyTransformForm& mat, const Point3dForm& offset);

    static applyTransformForm scale(const applyTransformForm& mat, const Point3dForm& scale);

    static Point3dForm normalize(const Point3dForm& vec);

    static applyTransformForm lookAt(const Point3dForm& vec1, const Point3dForm& vec2, const Point3dForm& vec3);

    static applyTransformForm perspective(double rad, double aspect, double zNear, double zFar);

    static applyTransformForm orthographic(double left, double right, double bottom, double top, double zNear, double zFar);

    static Point3dForm cross(const Point3dForm& v1, const Point3dForm& v2);
};


#endif //MODELVIEWER_TRANSFORMHELPER_H
