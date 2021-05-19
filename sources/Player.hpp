#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{

    class Player{
        protected:
        std::string role_;
        City current_city; // where the player is 
        std::unordered_set<City> cards;  // cities cards on player hands
        Board& board;

        //return random color - black , red , yellow , blue
        Color random_color();

        //check if the player had this specific card
        bool holds_card(City city);

        public:
        
        /* constractor */
        Player(Board& b, City city):board(b), current_city(city){
          this->cards = {};
        }

        /* destractor */
        ~Player(){}

        //Moving from the current city to a nearby city (according to the context map).
        virtual Player& drive(City city); 

        //Moving from the current city to the city of some card in player hand
        virtual Player& fly_direct(City city);

        /*Moving from the current city to any city.
          To do this, throw the appropriate card to the city you are in.
        */
        virtual Player& fly_charter(City city);

        /*If there is a research station in the current city,
         the player can fly to any other city that has a research station
        */
        virtual Player& fly_shuttle(City city);
        
        //build research station in the current city
        virtual void build();

        //Discovering a cure for a disease of a certain color
        virtual Player& discover_cure(Color color);

        //Treatment of the disease
        virtual Player& treat(City city); 

        //A function that returns the role of the player
        std::string role();

        //Taking some city card
        Player& take_card(City city);

        //remove all cards from player hand
        void remove_cards();
        
    };
}