#include "Meteor.hpp"


int main(int argc, char** arv)
{
    Meteor::Vector v(3);
    v.Fill(1.0f);
    
    Meteor::Node n(v);
    
    std::cout << n.ToString() << std::endl;
    
    
    return 0;
}
