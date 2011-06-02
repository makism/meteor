#ifndef _NODE_HPP
#define _NODE_HPP


namespace Meteor
{

    class METEOR_EXPORT Node
    {
    public:
        Node(void);
        Node(const Vector& vect);
        Node(const Node& node);
        ~Node(void);

        long unsigned int Id(void) const;
        Vector& RefVector(void);

        float& operator [](unsigned int index);
        float const& operator [](unsigned int index) const;
        bool operator ==(const Node& rhs) const;
        bool operator !=(const Node& rhs) const;

    protected:
        long unsigned int mId;
        Vector mRefVector;
    };

}

#endif
