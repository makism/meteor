#ifndef _MAP_HPP_
#define _MAP_HPP_


namespace Meteor
{
    
    class METEOR_EXPORT MapFactory
    {
    public:
        MapFactory(void);
        virtual ~MapFactory(void);
        
        //structs::NodeContainer* container;
        //structs::Vector* InputVector(void);
        
        virtual void Init(void) = 0;
        virtual void Train(void) = 0;
        
    protected:
        long unsigned int mIterations;
        //structs:Vector* mInput;
    };
    
}


#endif
