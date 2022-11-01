#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <iostream>
#include <stdbool.h>
#include <map>
#include <vector>

namespace pandemic{
    class Board{
        private:

        public:
        std::map<City,int> sick_cities; // <city,int - (int)disese level>
        std::map<City,bool> cities_stations; // <city,reserch station - ture/false>
        std::map<City,std::map<City,bool>> cities_and_neighbors; //<City,City,bool - ture/false - if neighbors>
        std::map<City,Color> cities_color; //<city,color>
        //for discover_cure and treat
        bool yellow_cure = false;
        bool red_cure = false;
        bool blue_cure = false;
        bool black_cure = false;

         /* constractor */
        Board();

        ~Board(){}
        /* deep copty constractor */
       // Board(Board& b);

        Board& operator[](City city);

        const Board operator[](City city) const;

        Board& operator=(int num);


        friend std::ostream& operator<<(std::ostream& os ,const Board& board);

        bool is_clean();

        void remove_cures();

        void remove_stations();


    };
}