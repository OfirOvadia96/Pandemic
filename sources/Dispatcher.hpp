
#include "Player.hpp"

namespace pandemic{

    class Dispatcher:public Player{
    private:
     
    public:
        Dispatcher(Board& board , City city):Player(board,city){
            this->role_ = "Dispatcher";
        }
        ~Dispatcher(){}
        Player& fly_direct(City city)override;
    };
    
}