#include "Medic.hpp"

namespace pandemic{

    Player& Medic::treat(City city){
         if(this->board[city] == 0){
            throw std::invalid_argument("A city free of disease!");
        }
        this->board[city] = 0;
        return *this;
    }

    Player& Medic::drive(City city){
         if(city == this->current_city){
            throw std::invalid_argument{"can't fly from city to itself!"};
        }

        if(!this->board.is_neighbors(this->current_city,city)){
           throw std::invalid_argument("the cities not neighbors");
        }
        
         this->current_city = city; //drive there and update current city
           
           if(this->board.exists_cure(this->board.get_color(city))){ 
                this->board[city] = 0; //the medic expertise
            }
            
        return *this;
    }

    Player& Medic::fly_direct(City city){
        if(city == this->current_city){
            throw std::invalid_argument{"can't fly from city to itself!"};
        }
        if(!holds_card(city)){
            throw std::invalid_argument{" Medeic don't have city card"};
        }
        if(holds_card(city)){
            this->cards.erase(city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
            if(this->board.exists_cure(this->board.get_color(city))){
                this->board[city] = 0;//the medic expertise
            }
        }
        return *this;
    }
    
    Player& Medic::fly_charter(City city){
         if(city == this->current_city){
            throw std::invalid_argument{"can't fly from city to itself!"};
        }

        if(holds_card(this->current_city)){
            this->cards.erase(this->current_city); //remove this card from player hand
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
        if(!this->board.exists_station(this->current_city) && !this->board.exists_station(city)){
            throw std::invalid_argument("no stations in src/dst city");
        }
         if(city == this->current_city){
            throw std::invalid_argument{"can't fly from city to itself!"};
        }

        this->current_city = city; //update the current city after fly
        if(this->board.exists_cure(this->board.get_color(city))){
            this->board[city] = 0;//the medic expertise
        }
        return *this;
    }
}