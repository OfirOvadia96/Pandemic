#include "Player.hpp"
using namespace std;
namespace pandemic{

    Player& Player::drive(City city){
        return *this;
    }
    Player& Player::fly_direct(City city){
      return *this;
    }
    Player& Player::fly_charter(City city){
        return *this;
    }
    Player& Player::fly_shuttle(City city){
       return *this;
    }
    void Player::build(){
       
    }
    void Player::discover_cure(Color color){
       
    }
    Player& Player::treat(City city){
        return *this;
    }
    std::string Player::role(){
       return role_;
    }
    Player& Player::take_card(City city){
       return *this;
    }

    void Player::remove_cards(){
        
    }
}