#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <vector>
#include "Board.hpp"

namespace pandemic{

    class Player{

        public:
        std::vector<City> cards; // cities cards on player hands
        City current_city; // where the player is 
        std::string role_;
        Board board;
        
        /* constractor */
        Player(Board b, City city){
            board = b; //called (board) deep copy constractor
            current_city = city; //where i am now
        }

        /* destractor */
        ~Player(){}

        Player& drive(City city);

        virtual Player& fly_direct(City city);

        Player& fly_charter(City city);

        Player& fly_shuttle(City city);
        
        virtual void build();

        virtual void discover_cure(Color color);

        virtual Player& treat(City city);

        std::string role();

        Player& take_card(City city);

        void remove_cards();

    };
}