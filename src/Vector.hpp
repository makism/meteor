#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_


namespace Meteor
{

    class METEOR_EXPORT Vector
    {
    public:
        Vector(void);
        Vector(unsigned int dimensions);
#ifndef __cplusplus_cli
        Vector(float p, ...);
#endif
        Vector(float x, float y, float z);
        Vector(float x, float y, float z, float w);
        Vector(std::vector<float> p);
        Vector(float* points, unsigned int dimensions);
        Vector(const Vector& v);
        ~Vector(void);

        Vector 	operator  -(Vector& v);
        Vector 	operator  +(Vector& v);
        Vector 	operator  *(const float mult);
        Vector  operator  /(const float dv);
        Vector& operator -=(Vector& v);
        Vector& operator +=(Vector& v);
        Vector& operator *=(const float mult);
        Vector& operator /=(const float dv);
        float&  operator [](unsigned int offset);
        float  const& operator [](unsigned int offset) const;
        bool    operator  >(const Vector& v) const;
        bool    operator  <(const Vector& v) const;
        bool    operator ==(const Vector& v) const;

        unsigned int     Dimensions(void);
        std::vector<float>  Points(void);

        void    Fill(float value);
        float   Magnitude(void);
        float   Dot(const Vector& v) const;
        Vector  Cross(const Vector& v) const;
        float   DistanceFrom(const Vector& v) const;

        static const Vector One(unsigned int dimensions);
        static const Vector Zero(unsigned int dimensions);

    private:
        unsigned int mDimensions;

        std::vector<float> mPoints;

        float mMagnitude;
    };

}

#endif
