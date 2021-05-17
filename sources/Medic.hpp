#include "Player.hpp"

namespace pandemic{

    class Medic:public Player{
    private:
  
    public:
        Medic(Board& board , City city):Player(board,city){
            this->role_ = "Medic";
        }
        ~Medic(){

        }

        Player& treat(City city)override;

        Player& drive(City city)override;
      
        Player& fly_direct(City city)override;
       
        Player& fly_charter(City city)override;

        Player& fly_shuttle(City city)override;
    
    };
}