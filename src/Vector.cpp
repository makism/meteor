#include "Meteor.hpp"


namespace Meteor
{

    Vector::Vector(void)
        : mDimensions(0), mMagnitude(0.0f)
    {

    }

    Vector::Vector(unsigned int dimensions)
        : mDimensions(dimensions), mMagnitude(0.0f)
    {

    }

#ifndef __cplusplus_cli
    Vector::Vector(float s, ...)
        : mDimensions(0), mMagnitude(0.0f)
    {
        va_list ap;
        va_start(ap, s);
        while (s) {
            mPoints.push_back(s);
            mDimensions++;

            s = va_arg(ap, const char *);
        }
        va_end(ap);
    }
#endif

    Vector::Vector(float x, float y, float z)
        : mDimensions(3), mMagnitude(0.0f)
    {
        mPoints.push_back(x);
        mPoints.push_back(y);
        mPoints.push_back(z);
    }

    Vector::Vector(float x, float y, float z, float w)
        : mDimensions(4), mMagnitude(0.0f)
    {
        mPoints.push_back(x);
        mPoints.push_back(y);
        mPoints.push_back(z);
        mPoints.push_back(w);
    }

    Vector::Vector(std::vector<float> p)
        : mPoints(p), mMagnitude(0.0f)
    {
        mDimensions = p.size();
    }

    Vector::Vector(float* points, unsigned int dimensions)
        : mDimensions(dimensions), mMagnitude(0.0f)
    {
        for (unsigned int i = 0; i < mDimensions; i++) {
            mPoints.push_back( *(points+i) );
        }
    }

    Vector::Vector(const Vector& v)
        : mMagnitude(0.0f)
    {
        mDimensions = v.mDimensions;

        for (unsigned int i = 0; i < mDimensions; i++) {
            mPoints.push_back(v.mPoints.at(i));
        }
    }

    Vector::~Vector(void)
    {

    }

    float Vector::Magnitude(void)
    {
        if (mMagnitude==0.0f) {
            for(unsigned int i=0;i<mDimensions;i++) {
                mMagnitude += pow(mPoints[i], 2.0f);
            }

            mMagnitude = sqrt(mMagnitude);
        }

        return mMagnitude;
    }

    void Vector::Fill(float value)
    {
        for(unsigned int i=0; i<mDimensions; i++){
            mPoints[i] = value;
        }
    }

    float& Vector::operator [](unsigned int offset)
    {
        if(offset<mDimensions)
            return mPoints[offset];
        else
            throw std::invalid_argument("Index out of boundaries."); 
    }

    float const& Vector::operator [](unsigned int offset) const
    {
        if(offset<mDimensions)
            return mPoints[offset];
        else
            throw std::invalid_argument("Index out of boundaries."); 
    }

    
    const Vector Vector::One(unsigned int dimensions) {
        Vector v(dimensions);
        v.Fill(1.0f);

        return v;
    }
    
    const Vector Vector::Zero(unsigned int dimensions) {
        Vector v(dimensions);
        v.Fill(0.0f);

        return v;
    }

}
