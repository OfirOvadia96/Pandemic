
#include "Player.hpp"
namespace pandemic{

    class GeneSplicer:public Player{
    private:
    
    public:
        GeneSplicer(Board board , City city):Player(board, city){
            this->role_ = "GeneSplicer";
        }
        ~GeneSplicer(){}
        void discover_cure(Color color)override;
    };
    
}