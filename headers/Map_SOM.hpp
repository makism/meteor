 #ifndef _MAP_SOM_HPP_
 #define _MAP_SOM_HPP_
 
 
 namespace Meteor
 {
     
     class METEOR_EXPORT Map_SOM
     {
     public:
         Map_SOM(void);
         virtual ~Map_SOM(void);
         
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
 