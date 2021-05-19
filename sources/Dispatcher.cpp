#include "Dispatcher.hpp"

namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
        if(city == this->current_city){
            throw std::invalid_argument{"can't fly from city to itself!"};
        }
        
        if(this->board.exists_station(this->current_city)){
            this->current_city = city;
        }
        else{
            if(!holds_card(city)){
                throw std::invalid_argument("no card");
            }
            this->current_city = city;
        }
        return *this;
    }
}