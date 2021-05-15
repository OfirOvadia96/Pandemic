#include "Researcher.hpp"

namespace pandemic{

     void Researcher::discover_cure(Color color){
        bool ans_cures = this->board.exists_cure(color);
        if(!ans_cures && this->cards.at(color).size() > 4){
            const int  more_then = 6;
            for(int i=0; i<more_then; i++){
               std::unordered_set<City>::iterator it = this->cards.at(color).begin();
               this->cards.at(color).erase(it); //throw card from hand player
            }
            this->board.new_cure_discovered(color);//update that the cure discovered
        }
     }
}