#ifndef DYNAMICGRAPH_HPP_
#define DYNAMICGRAPH_HPP_


namespace meteor {
    
        /*
        * A dynamic graph.
        */
        class METEOR_EXPORT DynamicGraph: public NodeContainer {
            
            public:
                DynamicGraph( void );
                DynamicGraph( Node ** startingNodes );
                ~DynamicGraph( void );
                
                void DeleteEdge( Edge * e );
                void DeleteEdges( std::vector<Edge *> * );
                
                Edge * ConnectNodes( Node * n1, Node * n2 );
                void DisconnectNodes( Node * n1, Node * n2 );
                
                std::vector<Edge *> * GetEdges( void );
                std::vector<Edge *> GetEdgesByNode( Node *  );
                std::vector<Edge *> GetEdgesByNode( long unsigned int );
                Edge * GetEdgeByNodes( Node * n1, Node * n2 );
                
                std::vector<Node *> GetNodeNeighbours( Node * );
                long unsigned int GetNumberOfEdgesByNode( Node * );
                
                long unsigned int NumberOfEdges( void );
            
            private:
                // The current number of nodes.
                long unsigned int numberOfEdges;
                
                // A vector holding all Edges in our graph.
                std::vector<Edge *> * edges;
                
                // The edges that each Node has.
                std::map<long unsigned int, std::vector<Edge *> > * nodes_edges;
            
        };

}

#endif
