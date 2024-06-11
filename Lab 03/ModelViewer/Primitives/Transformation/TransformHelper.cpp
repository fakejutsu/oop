//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "TransformHelper.h"


applyTransformForm TransformHelper::translate(const applyTransformForm& mat, const Point3dForm& offset)
{
    return glm::translate(mat, offset);
}

applyTransformForm TransformHelper::rotate(const applyTransformForm& mat, double rad, const Point3dForm& offset)
{
    return glm::rotate(mat, rad, offset);
}

inline double TransformHelper::radians(double degrees)
{
    return glm::radians(degrees);
}

applyTransformForm TransformHelper::rotate(const applyTransformForm& mat, const Point3dForm& offset)
{
    applyTransformForm mat2 = mat;
    mat2 = rotate(mat, radians(offset.x), Point3dForm(1.0f, 0.0f, 0.0f));
    mat2 = rotate(mat2, radians(offset.y), Point3dForm(0.0f, 1.0f, 0.0f));
    mat2 = rotate(mat2, radians(offset.z), Point3dForm(0.0f, 0.0f, -1.0f));
    return mat2;
}

applyTransformForm TransformHelper::scale(const applyTransformForm& mat, const Point3dForm& scale)
{
    return glm::scale(mat, scale);
}

Point3dForm TransformHelper::normalize(const Point3dForm& vec)
{
    return glm::normalize(vec);
}

applyTransformForm TransformHelper::lookAt(const Point3dForm& vec1, const Point3dForm& vec2, const Point3dForm& vec3)
{
    return glm::lookAt(vec1, vec2, vec3);
}

applyTransformForm TransformHelper::perspective(double rad, double aspect, double zNear, double zFar)
{
    return glm::perspective(rad, aspect, zNear, zFar);
}

applyTransformForm TransformHelper::orthographic(double left, double right, double bottom, double top, double zNear, double zFar)
{
    return glm::ortho(left, right, bottom, top, zNear, zFar);

}

Point3dForm TransformHelper::cross(const Point3dForm& v1, const Point3dForm& v2)
{
    return glm::cross(v1, v2);
}