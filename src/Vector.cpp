#include "Meteor.hpp"


namespace Meteor
{

Vector::Vector(void)
        : mDimensions(0),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{

}

Vector::Vector(const int dimensions)
        : mDimensions(dimensions),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{

}

#ifndef __cplusplus_cli
Vector::Vector(float s, ...)
        : mDimensions(0),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{
    va_list ap;
    va_start(ap, s);

    while (s) {
        mPoints.push_back(s);
        mDimensions++;

        s = va_arg(ap, double);
    }

    va_end(ap);
}
#endif

Vector::Vector(float x, float y, float z)
        : mDimensions(3),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{
    mPoints.push_back(x);
    mPoints.push_back(y);
    mPoints.push_back(z);
}

Vector::Vector(float x, float y, float z, float w)
        : mDimensions(4),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{
    mPoints.push_back(x);
    mPoints.push_back(y);
    mPoints.push_back(z);
    mPoints.push_back(w);
}

Vector::Vector(const std::vector<float>& p)
        : mPoints(p),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{
    mDimensions = p.size();
}

Vector::Vector(const float* points, int dimensions)
        : mDimensions(dimensions),
        mMagnitude(0.0f),
        mHasCalculatedMagnitude(false),
        mIsNormalized(false)
{
    for (unsigned int i = 0; i < mDimensions; i++) {
        mPoints.push_back(*(points + i));
    }
}

Vector::Vector(const Vector& v)
{
    mDimensions = v.mDimensions;
    mMagnitude = v.mMagnitude;
    mHasCalculatedMagnitude = v.mHasCalculatedMagnitude;
    mIsNormalized = v.mIsNormalized;

    for (int i = 0; i < mDimensions; i++) {
        mPoints.push_back(v.mPoints.at(i));
    }
}

Vector::~Vector(void)
{

}

float Vector::Magnitude(void)
{
    if (!mHasCalculatedMagnitude) {
        mMagnitude = sqrt(std::inner_product(mPoints.begin(), mPoints.end(), mPoints.begin(), 0.0f));

        mHasCalculatedMagnitude = true;
    }

    return mMagnitude;
}

void Vector::Normalize(void)
{
    if (!mIsNormalized) {
        for (unsigned int i = 0; i < mDimensions; i++) {
            mPoints[i] /= Magnitude();
        }
    }
}

void Vector::Fill(const float& value)
{
    for (unsigned int i = 0; i < mDimensions; i++)
        mPoints[i] = value;
}

float& Vector::operator [](int index)
{
    if (index < mDimensions)
        return mPoints[index];
}

float const& Vector::operator [](int index) const
{
    if (index < mDimensions)
        return mPoints[index];
}


const Vector Vector::One(int dimensions)
{
    Vector v(dimensions);
    v.Fill(1.0f);

    return v;
}

const Vector Vector::Zero(int dimensions)
{
    Vector v(dimensions);
    v.Fill(0.0f);

    return v;
}

const std::string Vector::ToString(void) const
{
    std::ostringstream oss;
    
    oss << "Vector";
    
    return oss.str();
}

}
