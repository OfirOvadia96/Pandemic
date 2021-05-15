#include "Scientist.hpp"

namespace pandemic{

    void Scientist::discover_cure(Color color){
        bool ans_cures = this->board.exists_cure(color);
        bool ans_station = this->board.exists_station(this->current_city);
        
        if(!ans_cures && ans_station && this->cards.at(color).size() >= this->discover_ability){
            for(int i=0; i<this->discover_ability; i++){
                std::unordered_set<City>::iterator it = this->cards.at(color).begin();
                this->cards.at(color).erase(it); //throw card from hand player
            }

            this->board.new_cure_discovered(color);//update theat the cure discovered
        }
    }
}