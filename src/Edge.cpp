#include "Meteor.hpp"


namespace meteor {
    
    namespace structs {
        
        // Initialization of the static property.
        long unsigned int Edge::counter = 0;
        
        #ifdef _WIN32
            void Edge::Reset( void ) {
                Edge:counter = 0;
            }
        #endif
        
        /*
        * Empty constructor.
        */
        Edge::Edge( void )
            : age( 0 ), id( -1 ) {
                
        }
        
        /*
        * Constructor.
        */
        Edge::Edge( Node * start, Node * end )
            : age( 0 ), id( Edge::counter++ ) {
            this->start = start;
            this->end = end;
        }
        
        /*
        * Empty destructor.
        */
        Edge::~Edge( void ) {
            //delete start;
            //delete end;
        }
        
        /*
        *
        */
        const std::string Edge::ToString( void ) {
            std::ostringstream oss;
            oss << "Edge #" << id << " (age: " << age << ") "
                << " connects \"" << start->ToString( ) << "\" with \""
                << end->ToString( ) << "\"";
                
            return oss.str( );
        }
        
        /*
        *
        */
        Node * Edge::Search( Node * n ) {
            if( start == n ) {
                return start;
                
            } else if( end == n ) {
                return end;
            }
        }
        
        /*
        * Returns the start (a node) of the edge.
        */
        Node * Edge::Start( void ) {
            return start;
        }
        
        /*
        * Returns the end (a node) of the edge.
        */
        Node * Edge::End( void ) {
            return end;
        }
        
        /*
        * Returns the unique id for this edge.
        */
         long unsigned int Edge::Id( void ) {
            return id;
        }
        
        /*
        * Increases the edge`s age.
        */
        void Edge::Age( void ) {
            age++;
        }
        
    }

}
