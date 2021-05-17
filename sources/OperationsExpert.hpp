#include "Player.hpp"
namespace pandemic{

    class OperationsExpert: public Player{
        private:
        
        public:
            /* constractor */
            OperationsExpert(Board& board , City city):Player(board,city){
            this->role_ = "OperationsExpert";
            }

            /* destractor */
            ~OperationsExpert(){}

            void build()override;
    };
    
}