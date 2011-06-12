#ifndef NODE_HPP_
#define NODE_HPP_


namespace Meteor {

class METEOR_EXPORT Node {
public:
    Node(void);
    Node(const Vector& v);
    Node(const Node& n);
    virtual ~Node(void);

    long unsigned int Id(void) const;
    Vector& RefVector(void);
    float* RefVectorPoints(void) const;

    virtual const std::string ToString(void) const;
    
protected:
    /*! */
    Vector refVector;

    /*! */
    long unsigned int id;

    /*! */
    static long unsigned int counter;
};

}

#endif
