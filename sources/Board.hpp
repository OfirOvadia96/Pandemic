#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <iostream>
#include <stdbool.h>
#include <map>
#include <unordered_set>

namespace pandemic{
    class Board{
        private:
        std::map<City,int> sick_cities; // <city,int - (int)disese level>
        std::map<City,Color> cities_color; //<city,color>
        std::map<City,std::unordered_set<City>> cities_and_neighbors; //<City,set - contains the neighbors>
        std::unordered_set<City> cities_stations; // set - that contains all the cities that has a reaserch station
        std::unordered_set<Color> discovered_cures; //What a cure was discovered - red,yellow,black,blue

        public:

         /* constractor */
        Board();

        /* destractor */
        ~Board(){}

        int& operator[](City city);


        friend std::ostream& operator<<(std::ostream& os ,const Board& board);

        //check if the board clean from disese
        bool is_clean();

        //clean the board from all the cures 
        void remove_cures();

        //clean the board from reaserch stations
        void remove_stations();

         // return the color of the city he receives
        Color which_color(City city);

        // check if this cure already discovered
        bool exists_cure(Color color);

        //check if in the city there is a research station
        bool exists_station(City city);

         void build_station(City city);

        bool is_neighbors(City city1 , City city2);

        //get color of specific city
        Color get_color(City city);
        
        // cure was discoverd
        void new_cure_discovered(Color color); 

    };
}