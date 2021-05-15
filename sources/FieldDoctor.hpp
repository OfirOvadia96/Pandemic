#include "Player.hpp"

namespace pandemic{

    class FieldDoctor:public Player{
        
    public:
        FieldDoctor(Board board , City city):Player(board ,city){
            this->role_ = "FieldDocotor";
        }
        ~FieldDoctor(){}
        Player& treat(City city)override;
    };
    
}