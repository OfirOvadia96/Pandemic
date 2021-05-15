#include "Player.hpp"
using namespace std;
namespace pandemic{

    bool Player::holds_card(City city){
        bool ans = false;
        for(const auto& pair : this->cards){
            for(const City c : pair.second){
                if(c == city){
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }

    Player& Player::drive(City city){
        // if not the same city and if there are neighbors
        if(city != this->current_city && this->board.is_neighbors(this->current_city,city)){
           this->current_city = city; //drive there and update current city
        }
        return *this;
    }

    Player& Player::fly_direct(City city){
        if(city != this->current_city && holds_card(city)){
            this->cards.at(this->board.get_color(city)).erase(city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
        }
        return *this;
    }
    
    Player& Player::fly_charter(City city){
        if(city != this->current_city && holds_card(this->current_city)){
            this->cards.at(this->board.get_color(this->current_city)).erase(this->current_city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
        }
        return *this;
    }

    Player& Player::fly_shuttle(City city){
        /*check if there are reaserch stations in both cities and
          even if the city the player wants to fly to is not the current city he is already in
        */
        if(city != this->current_city && this->board.exists_station(this->current_city)&&
        this->board.exists_station(city)){
             this->current_city = city; //update the current city after fly
        }
        return *this;
    }
    
    void Player::build(){
        bool ans = this->board.exists_station(this->current_city);
        if(!ans && holds_card(this->current_city)){ //if the player had the currect card and there is no reaserch station
            this->cards.at(this->board.get_color(this->current_city)).erase(this->current_city); //throw the card from the hand player
            this->board.build_station(this->current_city);//build the reaserch station
        }
    }

    void Player::discover_cure(Color color){
        bool ans_cures = this->board.exists_cure(color);
        bool ans_station = this->board.exists_station(this->current_city);
        if(!ans_cures && ans_station && this->cards.at(color).size() > 4){
            for(int i=0; i<6; i++){
                unordered_set<City>::iterator it = this->cards.at(color).begin();
                this->cards.at(color).erase(it); //throw card from hand player
            }
            this->board.new_cure_discovered(color);//update theat the cure discovered
        }
    }

    Player& Player::treat(City city){
        if(this->board.level_disese_in_the_city(this->current_city) == 0){
            throw invalid_argument("A city free of disease!");
        }
        //if cure already exists
        if(this->board.exists_cure(this->board.get_color(city))){
            this->board[this->current_city] = 0;
        }
        else{ //if cure not exists
            this->board[this->current_city] = (this->board[this->current_city]-1);
        }
        return *this;
    }

    std::string Player::role(){
       return role_;
    }

    Player& Player::take_card(City city){
        this->cards.at(this->board.get_color(city)).insert(city);
       return *this;
    }

    void Player::remove_cards(){
        this->cards.clear();
    }
}