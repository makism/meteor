#include "Meteor.hpp"


int main(int argc, char** arv)
{
    Meteor::Vector v(3);
    v.Fill(1.0f);
    
    std::cout << v.ToString() << std::endl;
    
    return 0;
}
