#include "Scientist.hpp"
using namespace std;
namespace pandemic{

    Player& Scientist::discover_cure(Color color){
        bool ans_cures = this->board.exists_cure(color);
        bool ans_station = this->board.exists_station(this->current_city);
        
        int  count = 0;
        for(City c : this->cards){
            if(this->board.get_color(c) == color){
                count++;
            }
        }
        if(!ans_station){
            throw invalid_argument{" Scientist - no reaserch station"};
        }

        if(count < this->discover_ability){
            throw invalid_argument("The Player doesn't have enough cards!");
        }
        
        if(!ans_cures){
           std::unordered_set<City> temp_cards;
            
            //copy the cards
            for(City card:this->cards){
                temp_cards.insert(card);
            }
           
            int counter = 0;
            //erase n cards of the same color from the player hand
            for(City card : this->cards){
                if(this->board.get_color(card) == color){
                    temp_cards.erase(card);
                    if(counter == this->discover_ability-1){
                        break;
                    }
                    counter++;
                }
            }
            //clear the cards from player hand
            this->cards.clear();
           
            //adds back the remaining cards
            for(City card : temp_cards){
                this->cards.insert(card);
            }

            this->board.new_cure_discovered(color);//update that the cure discovered
        }
        return *this;
    }
}