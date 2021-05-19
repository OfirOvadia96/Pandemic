#include "Player.hpp"
#include <array>
using namespace std;
namespace pandemic{

    bool Player::holds_card(City city){
        bool ans = false;
        for(const City c : this->cards){
            if(c == city){
                ans = true;
                break;
            }
        }
        return ans;
    }

    Player& Player::drive(City city){
        if(this->current_city == city){
            throw invalid_argument{"can't fly from city to itself"};
        }
        if(!this->board.is_neighbors(this->current_city,city)){
           throw invalid_argument("the cities not neighbors");
        }

        this->current_city = city; //drive there and update current city

        return *this;
    }

    Player& Player::fly_direct(City city){
         if(this->current_city == city|| !holds_card(city)){
            throw invalid_argument{"can't fly from city to itself"};
        }

            this->cards.erase(city); //remove this card from player hand
            this->current_city = city; //update the current city after fly
        return *this;
    }
    
    Player& Player::fly_charter(City city){
         if(this->current_city == city){
            throw invalid_argument{"can't fly from city to itself"};
        }

        if(!holds_card(this->current_city)){
            throw invalid_argument{"don't have this city card"};
        }

        this->cards.erase(this->current_city); //remove this card from player hand
        this->current_city = city; //update the current city after fly
        return *this;
    }

    Player& Player::fly_shuttle(City city){
        /*check if there are reaserch stations in both cities and
          even if the city the player wants to fly to is not the current city he is already in
        */
        if(!this->board.exists_station(this->current_city) || !this->board.exists_station(city)){
            throw invalid_argument("no stations in src/dst city");
        }

        if(city == this->current_city){
            throw invalid_argument("can't fly from city to itself");
        }

        this->current_city = city; //update the current city after fly
        return *this;
    }
    
    void Player::build(){
        if(!holds_card(this->current_city)){
            throw invalid_argument("don't have the currect card");
        }

        bool ans = this->board.exists_station(this->current_city);
        if(!ans){ //if the player had the currect card and there is no reaserch station
            this->cards.erase(this->current_city); //throw the card from the hand player
            this->board.build_station(this->current_city);//build the reaserch station
        }
    }

    Player& Player::discover_cure(Color color){
        int  count = 0;
        //counting how many cards the player had
        for(City c : this->cards){
            if(this->board.get_color(c) == color){
                count++;
            }
        }
        const int more_then = 5;
        if(count < more_then){
            throw invalid_argument{"Player don't have enough cards!"};
        }
        
        bool ans_station = this->board.exists_station(this->current_city);
        if(!ans_station){
            throw invalid_argument{"no reaserch station!"};
        }

        bool ans_cures = this->board.exists_cure(color);
        if(!ans_cures){
           unordered_set<City> temp_cards;
            
            //copy the cards
            for(City card:this->cards){
                temp_cards.insert(card);
            }
           
            int counter = 0;
            //erase 5 cards of the same color from the player hand
            for(City card : this->cards){
                if(this->board.get_color(card) == color){
                    temp_cards.erase(card);
                    if(counter == 4){
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

    Player& Player::treat(City city){
        if(city != this->current_city){
            throw invalid_argument("not in the current city");
        }

        if(this->board[this->current_city] == 0){
            throw invalid_argument("A city free of disease!");
        }

        //if cure already exists
        if(this->board.exists_cure(this->board.get_color(city))){
            this->board[this->current_city] = 0;
        }

        else{ //if cure not exists
            this->board[this->current_city]--;
        }

        return *this;
    }

    std::string Player::role(){
       return role_;
    }

    Player& Player::take_card(City city){
        this->cards.insert(city);
       return *this;
    }

    void Player::remove_cards(){
        this->cards.clear();
    }
}