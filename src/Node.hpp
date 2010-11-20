#ifndef _NODE_HPP
#define _NODE_HPP


namespace Meteor
{

    class METEOR_EXPORT Node
    {
    public:
        Node(void);
        Node(Vector& v);
        Node(const Node& b);
        ~Node(void);

        bool operator ==(Node& rhs);
        bool operator !=(Node& rhs);

    protected:
        Vector& mRefVector;
    };

}

#endif
