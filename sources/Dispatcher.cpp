#include "Dispatcher.hpp"

namespace pandemic{

    Player& Dispatcher::fly_direct(City city){
        if(city != this->current_city && this->board.exists_station(this->current_city)){
            this->current_city = city;
        }
        return *this;
    }
}