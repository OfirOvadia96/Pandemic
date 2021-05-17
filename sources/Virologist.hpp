#include "Player.hpp"

namespace pandemic{
    class Virologist: public Player{
    private:
 
    public:
        Virologist(Board& board , City city):Player(board,city){
            this->role_ = "Virologist";
        }
        ~Virologist(){}
        Player& treat(City city)override;
    };
    
}