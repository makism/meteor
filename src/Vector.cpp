#include "Meteor.hpp"


namespace Meteor
{

    Vector::Vector(void)
        : mDimensions(0), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {

    }

    Vector::Vector(unsigned int dimensions)
        : mDimensions(dimensions), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {

    }

#ifndef __cplusplus_cli
    Vector::Vector(float s, ...)
        : mDimensions(0), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {
        va_list ap;
        va_start(ap, s);

        while (s) {
            mPoints.push_back(s);
            mDimensions++;

            s = va_arg(ap, float);
        }

        va_end(ap);
    }
#endif

    Vector::Vector(float x, float y, float z)
        : mDimensions(3), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {
        mPoints.push_back(x);
        mPoints.push_back(y);
        mPoints.push_back(z);
    }

    Vector::Vector(float x, float y, float z, float w)
        : mDimensions(4), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {
        mPoints.push_back(x);
        mPoints.push_back(y);
        mPoints.push_back(z);
        mPoints.push_back(w);
    }

    Vector::Vector(std::vector<float> p)
        : mPoints(p), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
    {
        mDimensions = p.size();
    }

    Vector::Vector(float* points, unsigned int dimensions)
        : mDimensions(dimensions), mMagnitude(0.0f), mHasCalculatedMagnitude(false)
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

        for (unsigned int i = 0; i < mDimensions; i++) {
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
        for (unsigned int i = 0; i < mDimensions; i++) {
            mPoints[i] /= Magnitude();
        }
    }

    void Vector::Fill(float value)
    {
        for (unsigned int i = 0; i < mDimensions; i++) {
            mPoints[i] = value;
        }
    }

    float& Vector::operator [](unsigned int index)
    {
        if (index < mDimensions)
            return mPoints[index];

        else
            throw std::invalid_argument("Index out of boundaries.");
    }

    float const& Vector::operator [](unsigned int index) const
    {
        if (index < mDimensions)
            return mPoints[index];

        else
            throw std::invalid_argument("Index out of boundaries.");
    }


    const Vector Vector::One(unsigned int dimensions)
    {
        Vector v(dimensions);
        v.Fill(1.0f);

        return v;
    }

    const Vector Vector::Zero(unsigned int dimensions)
    {
        Vector v(dimensions);
        v.Fill(0.0f);

        return v;
    }

}
