#ifndef NODECONTAINER_HPP_ 
#define NODECONTAINER_HPP_


namespace meteor {
    
        /*
        * A graph.
        */
        class METEOR_EXPORT NodeContainer {
            
            public:
                // Best matching unit
                Node *bmu;
                
                // Second matching unit
                Node *smu;
                
                
                NodeContainer( void );
                ~NodeContainer( void );
                
                void AddNode( Node * n );
                void DeleteNode( Node * n, bool b );
                void DeleteNode( Node * n );
                void DeleteNodes( std::vector<Node *> * );
                
                std::vector<Node *> * GetNodes( void );
                
                Node * GetNodeById( long unsigned int id );
                Node * GetNode( long unsigned int index );
                
                long unsigned int NumberOfNodes( void );
            
            protected:
                // A vector holding all Nodes in our graph.
                std::vector<Node *> * nodes;
                
                // The current number of nodes.
                long unsigned int numberOfNodes;
        };

}

#endif
