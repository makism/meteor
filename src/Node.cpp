#include "Meteor.hpp"


namespace Meteor
{

    Node::Node(void)
    {
    }

    Node::Node(const Vector& vect)
        : mRefVector(vect)
    {
    }

    Node::Node(const Node& node)
    {
        mId = node.mId;
        mRefVector = node.mRefVector;
    }

    Node::~Node(void)
    {
    }

    long unsigned int Node::Id(void) const
    {
        return mId;
    }

    Vector& Node::RefVector(void)
    {
        return mRefVector;
    }

    float& Node::operator [](unsigned int index)
    {
        return mRefVector[index];
    }

    float const& Node::operator [](unsigned int index) const
    {
        return mRefVector[index];
    }

    bool Node::operator ==(const Node& rhs) const
    {
        return true;
    }

    bool Node::operator !=(const Node& rhs) const
    {
        return true;
    }

}
