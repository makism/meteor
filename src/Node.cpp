#include "Meteor.hpp"


namespace Meteor {

// Reset id counter.
long unsigned int Node::counter = 0;

/*
* Empty constructor.
*/
Node::Node(void)
        : id(-1)
{

}

/*
* Copy constructor.
*/
Node::Node(const Node& n)
{
    id = n.id;
}

/*
* Create a node with the given position.
*/
Node::Node(const Vector& v)
        : id(Node::counter++)
{
    refVector = new Vector(v);
}

/*
* Empty destructor.
*/
Node::~Node(void)
{
    delete refVector;
}

/*
*
*/
const std::string Node::ToString(void) const
{
    std::ostringstream oss;
    
    oss << "Node #" << id << " "
        << refVector->ToString();

    return oss.str();
}

/*
*
*/
long unsigned int Node::Id(void) const
{
    return id;
}

/*
*
*/
Vector* Node::RefVector(void)
{
    return refVector;
}

}
