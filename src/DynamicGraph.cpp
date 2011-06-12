#include "Meteor.hpp"


namespace meteor {
    
    namespace structs {
        
        /*
        * Empty constructor.
        */
        DynamicGraph::DynamicGraph( void )
            : NodeContainer( ) {
            
        }
        
        /*
        * Creates a dynamic grpah with the passed starting nodes.
        */
        DynamicGraph::DynamicGraph( Node ** startingNodes )
            : NodeContainer( ), numberOfEdges( 0 ) {
            
            edges = new std::vector<Edge *>;
            nodes_edges = new std::map<long unsigned int , std::vector<Edge *> >;
            
            numberOfNodes = 2;
            
            #if VERBOSE
                std::cout << "Created dynamic graph with starting nodes: " << std::endl;
            #endif
            
            for( long unsigned int i=0; i<numberOfNodes; i++ ) {
                nodes->push_back( new structs::Node( *(startingNodes[i]) ) );
                
                #if VERBOSE
                    std::cout << "\t";
                    std::cout << nodes->at( i )->ToString( ) << std::endl;
                #endif
            }
            
            ConnectNodes( nodes->at( 0 ), nodes->at( 1 ) );
        }
        
        /*
        * Empty destructor.
        */
        DynamicGraph::~DynamicGraph( void ) {
            delete edges;
            delete nodes_edges;
        }
        
        /*
        * Deletes a node and all edges that it`s connected to.
        */
        /*void DynamicGraph::DeleteNode( Node * n, bool flag ) {
            int edges = GetNumberOfEdgesByNode( n );
            
            if( edges > 0 ) {
                for( int i=0; i<edges; i++ ) {
                    DeleteEdge( (*nodes_edges)[n->Id( )].at( i ) );
                }
            }
            
            DeleteNode( n );
        }*/
        
        /*
        * Deletes a node.
        */
        /*void DynamicGraph::DeleteNode( Node * n ) {
            for( int i=0; i<nodes->size( ); i++ ) {
                Node * curr = nodes->at( i );
                
                if( curr == n ) {
                    #ifdef VERBOSE
                        std::cout << "Deleting node \"" << n->ToString( ) << "\"." << std::endl;
                    #endif
                    
                    nodes->erase( nodes->begin( ) + i );
                    
                    nodes_edges->erase( nodes_edges->find( n->Id( ) ) );
                    
                    numberOfNodes--;
                    
                    break;
                }
            }
        }*/
        
        /*
        * Returns all edges.
        */
        std::vector<Edge *> * DynamicGraph::GetEdges( void ) {
            return edges;
        }
        
        /*
        * Returns the current number of edges.
        */
        long unsigned int DynamicGraph::NumberOfEdges( void ) {
            return numberOfEdges;
        }
        
        /*
        * Deletes an edge.
        */
        void DynamicGraph::DeleteEdge( Edge * e ) {
            for( long unsigned int i=0; i<numberOfEdges; i++ ) {
                if( edges->at( i ) == e ) {
                    
                    // Disconnect the node.
                    DisconnectNodes( e->Start( ), e->End( ) );
                    
                    #if VERBOSE
                        std::cout << "Deleting edge \"" << e->ToString( ) << "\"." << std::endl;
                    #endif
                    
                    // Free the memory.
                    delete edges->at( i );
                    
                    // Remove from the vector.
                    edges->erase( edges->begin( ) + i );
                    
                    numberOfEdges--;
                    
                    break;
                }
                
            }
        }
        
        /*
        * Massive edge deletion.
        */
        void DynamicGraph::DeleteEdges( std::vector<Edge * > * edges ) {
            for( long unsigned int i=0; i<edges->size( ); i++ ) {
                DeleteEdge( edges->at( i ) );
            }
        }
        
        /*
        * Connects two nodes.
        */
        Edge * DynamicGraph::ConnectNodes( Node * n1, Node * n2 ) {
            Edge * conn = new Edge( n1, n2 );
            
            (*nodes_edges)[ n1->Id( ) ].push_back( conn );
            (*nodes_edges)[ n2->Id( ) ].push_back( conn );
            edges->push_back( conn );
            
            numberOfEdges++;
            
            #if VERBOSE
                std::cout << "New edge created. Connecting \""
                        << n1->ToString( )
                        << "\" with \""
                        << n2->ToString( )
                        << "\"."
                        << std::endl;
            #endif
            
            return conn;
        }
        
        /*
        * Disconnects two nodes.
        */
        void DynamicGraph::DisconnectNodes( Node * n1, Node * n2 ) {
            // Delete n1`s edge reference.
            for( long unsigned int i=0; i<GetNumberOfEdgesByNode( n1 ); i++ ) {
                Edge * e = (*nodes_edges)[n1->Id( )].at( i );
                
                if( (e->Start( )==n1 && e->End()==n2) ||
                    (e->Start()==n2 && e->End()==n1) )
                {
                    // Remove from the vector.
                    (*nodes_edges)[n1->Id( )].erase(
                        (*nodes_edges)[n1->Id( )].begin( ) + i
                    );
                    
                    break;
                }
            }
            
            // Delete n2`s edge reference.
            for( long unsigned int i=0; i<GetNumberOfEdgesByNode( n2 ); i++ ) {
                Edge * e = (*nodes_edges)[n2->Id( )].at( i );
                
                if( (e->Start( )==n1 && e->End()==n2) ||
                    (e->Start()==n2 && e->End()==n1) )
                {
                    // Remove from the vector.
                    (*nodes_edges)[n2->Id( )].erase(
                        (*nodes_edges)[n2->Id( )].begin( ) + i
                    );
                    
                    break;
                }
            }
        }
        
        /*
        * Returns the edge for the specified two nodes.
        */
        Edge * DynamicGraph::GetEdgeByNodes( Node * n1, Node * n2 ) {
            for( long unsigned int i=0; i<GetNumberOfEdgesByNode( n1 ); i++ ) {
                Edge * curr = (*nodes_edges)[n1->Id( )].at( i );
                
                if( (curr->Start( ) == n1 && curr->End( ) == n2) ||
                    (curr->End( ) == n1 && curr->Start( ) == n2 ) )
                {
                    return curr;
                }
            }
            
            return NULL;
        }
        
        /*
        * Returns the edges for the specified node.
        */
        std::vector<Edge *> DynamicGraph::GetEdgesByNode( long unsigned int id ) {
            return (*nodes_edges)[id];
        }
        std::vector<Edge *> DynamicGraph::GetEdgesByNode( Node * n ) {
            return (*nodes_edges)[n->Id( )];
        }
        
        /*
        * Returns a vector containing the neighbour nodes for the given node.
        */
        std::vector<Node *> DynamicGraph::GetNodeNeighbours( Node * n ) {
            std::vector<Node *> neighbours;
            std::vector<Edge *> edges = GetEdgesByNode( n );
            
            for( long unsigned int i=0; i<edges.size( ); i++ ) {
                Edge * e = edges.at( i );
                
                if( e->Start( ) == n ) {
                    neighbours.push_back( e->End( ) );
                } else {
                    neighbours.push_back( e->Start( ) );
                }
                
            }
            
            return neighbours;
        }
        
        /*
        * Returns the total number of edges that a node connects to.
        */
        long unsigned int DynamicGraph::GetNumberOfEdgesByNode( Node * n ) {
            return (*nodes_edges)[n->Id( )].size( );
        }
        
    }

}
