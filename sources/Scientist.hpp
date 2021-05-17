
#include "Player.hpp"
namespace pandemic{

    class Scientist:public Player{
    private:
        int discover_ability;
    public:
        Scientist(Board& board , City city,const int n):Player(board, city){
            this->role_ = "Scientist";
            this->discover_ability = n;
        }

        ~Scientist(){}
        Player& discover_cure(Color color) override;
    };
    
}