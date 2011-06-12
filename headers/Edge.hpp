#ifndef EDGE_HPP_
#define EDGE_HPP_


namespace meteor {
    
    namespace structs {
        
        /*
        * An edge that connects two nodes.
        */
        class METEOR_EXPORT Edge {
            
            public:
                // Edge`s age.
                int age;
                
                
                Edge( void );
                Edge( Node *, Node * );
                ~Edge( void );
                
                void	Age( void );
                
                long unsigned int		Id( void );
                
                Node *	Search( Node * );
                Node * 	Start( void );
                Node * 	End( void );
                
                const std::string ToString( void );
                
                /*
                * Reset the global edge counter.
                */
                #ifdef _WIN32
                static void Reset( void );
                #else
                static METEOR_EXPORT void Reset( void ) {
                    Edge::counter = 0;
                }
                #endif
                
            private:
                // A global edge counter.
                static long unsigned int counter;
                
                // Unique id.
                long unsigned int id;
                
                // The start point (node) of the edge.
                Node * start;
                
                // The end point (node) of the edge.
                Node * end;
        };
        
    }

}


#endif
