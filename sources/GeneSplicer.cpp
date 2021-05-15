#include "GeneSplicer.hpp"

namespace pandemic{

    void GeneSplicer::discover_cure(Color color){
        bool ans_cures = this->board.exists_cure(color);
        bool ans_station = this->board.exists_station(this->current_city);
        int amount_of_cards = 0;
        //check how many cards the player holds
        for(const auto pair :this->cards){
            amount_of_cards += pair.second.size();
        }

        if(!ans_cures && ans_station && amount_of_cards > 4){
            const int  more_then = 6;
            for(int i=0; i<more_then; i++){
                //need fix !!!!!!!!!!!!!!!!!! how we choose what cards to remove from player hand!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                std::unordered_set<City>::iterator it = this->cards.at(color).begin();
                this->cards.at(color).erase(it); //throw card from hand player
            }

            this->board.new_cure_discovered(color);//update that the cure discovered
        }
    }
}