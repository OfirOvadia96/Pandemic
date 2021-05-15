#include "Medic.hpp"

namespace pandemic{

    Player& Medic::treat(City city){
         if(this->board.level_disese_in_the_city(city) == 0){
            throw std::invalid_argument("A city free of disease!");
        }
        else{
            this->board[city] = 0;
        }
        return *this;
    }

    Player& Medic::drive(City city){
         // if not the same city and if there are neighbors
        if(city != this->current_city && this->board.is_neighbors(this->current_city,city)){
           this->current_city = city; //drive there and update current city
           if(this->board.exists_cure(this->board.get_color(city))){ 
                this->board[city] = 0; //the medic expertise
            }
        }
        return *this;
    }

    Player& Medic::fly_direct(City city){
        if(city != this->current_city && holds_card(city)){
            this->cards.at(this->board.get_color(city)).erase(city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
            if(this->board.exists_cure(this->board.get_color(city))){
                this->board[city] = 0;//the medic expertise
            }
        }
        return *this;
    }
    
    Player& Medic::fly_charter(City city){
        if(city != this->current_city && holds_card(this->current_city)){
            this->cards.at(this->board.get_color(this->current_city)).erase(this->current_city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
            if(this->board.exists_cure(this->board.get_color(city))){
                this->board[city] = 0;//the medic expertise
            }
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City city){
        /*check if there are reaserch stations in both cities and
          even if the city the player wants to fly to is not the current city he is already in
        */
        if(city != this->current_city && this->board.exists_station(this->current_city)&&
        this->board.exists_station(city)){
             this->current_city = city; //update the current city after fly
             if(this->board.exists_cure(this->board.get_color(city))){
                this->board[city] = 0;//the medic expertise
            }
        }
        return *this;
    }
}