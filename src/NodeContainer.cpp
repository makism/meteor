#include "Meteor.hpp"


namespace meteor {

    namespace structs {
        
        /*
         *
         */
        NodeContainer::NodeContainer( void )
            : numberOfNodes( 0 ) {
            nodes = new std::vector<Node *>;
        }
        
        /*
         *
         */
        NodeContainer::~NodeContainer( void ) {
            delete nodes;
        }
        
        /*
        * Adds a node.
        */
        void NodeContainer::AddNode( Node * n ) {
            numberOfNodes++;
            
            // Add the node to the vector.
            nodes->push_back( n );
        }
        
        /*
        * Deletes a node.
        */
        void NodeContainer::DeleteNode( Node * n ) {
            for( long unsigned int i=0; i<nodes->size( ); i++ ) {
                Node * curr = nodes->at( i );
                
                if( curr == n ) {
                    #if VERBOSE
                    std::cout << "Deleting node \"" << n->ToString( ) << "\"." << std::endl;
                    #endif
                    
                    nodes->erase( nodes->begin( ) + i );
                    delete curr;
                    curr = NULL;
                    //delete &(nodes[i]);
                    
                    numberOfNodes--;
                    
                    break;
                }
            }
        }
        
        /*
        * Massive node deletion.
        */
        void NodeContainer::DeleteNodes( std::vector<Node *> * nodes ) {
            for(  long unsigned int i=0; i<nodes->size( ); i++ ) {
                DeleteNode( nodes->at( i ) );
            }
        }

        /*
        * Returns all nodes.
        */
        std::vector<Node *> * NodeContainer::GetNodes( void ) {
            return nodes;
        }
        
        /*
         *
         */
        structs::Node * NodeContainer::GetNode(  long unsigned int index ) {
            return nodes->at( index );
        }
        
        /*
         *
         */
        structs::Node * NodeContainer::GetNodeById(  long unsigned int id ) {
            for(  long unsigned int i=0; i<nodes->size( ); i++ ) {
                if( nodes->at( i )->Id( ) == id ) {
                   return nodes->at( i );
                }
            }
        }
        
        /*
        * Returns the current number of nodes.
        */
         long unsigned int NodeContainer::NumberOfNodes( void ) {
            return numberOfNodes;
        }
        
    }
    
}
