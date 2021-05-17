#include "Player.hpp"

namespace pandemic{

    class Researcher:public Player{
    private:
        
    public:
        Researcher(Board& board , City city):Player(board,city){
            this->role_ = "Researcher";
        }
        ~Researcher(){}
        Player& discover_cure(Color color)override;
    };
    
}