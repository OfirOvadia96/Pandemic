#include "doctest.h"
#include "Board.hpp"
#include "FieldDoctor.hpp"
#include "OperationsExpert.hpp"
#include "Medic.hpp"
#include "Dispatcher.hpp"
#include "Virologist.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "GeneSplicer.hpp"
#include <array>
using namespace pandemic;

    /*------------Auxiliary functions------------- */

    //function for choose a random city
    City random_city(){
        const int size = 48;
        std::array<pandemic::City,size> Cities = {City::Algiers,City::Atlanta,City::Baghdad,City::Bangkok,City::Beijing,City::Bogota,
            City::BuenosAires,City::Cairo,City::Chennai,City::Chicago,City::Delhi,City::Essen,City::HoChiMinhCity,City::HongKong,
            City::Istanbul,City::Jakarta,City::Johannesburg,City::Karachi,City::Khartoum,City::Kinshasa,City::Kolkata,City:: Lagos,
            City::Lima,City:: London,City:: LosAngeles,City::Madrid,City::Manila,City::MexicoCity,City:: Miami,City::  Milan,
            City::Montreal,City::Moscow,City::Mumbai,City::NewYork,City:: Osaka,City::Paris,City::Riyadh,City::SanFrancisco,
            City::Santiago,City::SaoPaulo,City::Seoul,City::Shanghai,City::StPetersburg,City::Sydney,City::Taipei,City::Tehran,
            City::Tokyo,City::Washington};

        return (Cities[rand()%size]);
    }

    /*gives a random int - for disease level*/
    int random_level_disease(){
        return ((int)rand()%5 + 1); // 1-4
    }

    //clean the board from disease
    void remove_all_disese(Board& board){
        for (auto& disease : board.sick_cities){
            disease.second = 0;
        }
    }

    /*auxiliary function to check if the player holds specific card
    reutrn true - if so
    return false -if not  */
    bool contains_card(Player& player , City temp_city){
        for(unsigned int i=0; i<player.cards.size(); i++){// goes through the vector that describes the player cards
            if(player.cards.at(i) == temp_city){
                return true;
            }
        }
        return false;
    }

    /*check if 2 cities are neighbors or not*/
    bool if_neighbors(Board& board,Player& player, City city){
        return (board.cities_and_neighbors.at(player.current_city).at(city));
    }
    /*check if there is a reaserch station in the specific city
    return ture -if so
    return false - if not  */
    bool there_is_station(Board& board,City city){
        return (board.cities_stations.at(city));
    }

    /*-------------Tests------------------*/

TEST_CASE("Board-Tests"){
    Board board;
    CHECK(board.is_clean()==true);
    
    //operator []
    for(int i=0; i<50; i++){
        City c = random_city();
        int ran =  random_level_disease();
        board[c] = ran;
        CHECK(board.sick_cities.at(c) == ran); // check if the map that hold all the sick cities is update from the operator[]
    }
    //now they are sick cities on the board    
     CHECK(board.is_clean()==false);

    remove_all_disese(board);// clean the sick cities from the disease
    CHECK(board.is_clean()==true);
}


TEST_CASE("Player - Tests"){
    Board board;
    Player player1(board,random_city());
    Player player2(board,random_city()); //created only for comparison

    //drive func
    for(int i=0; i<50; i++){
        City temp_city = random_city(); // choose random city
        
        //if there are neighbors:
        if(if_neighbors(board,player1,temp_city)){
        player2.current_city = temp_city;  //update the other player (only for comparison)
        player1.drive(temp_city); // drive to random city
        CHECK(player1.current_city == player2.current_city);
        }
        else{
            CHECK_THROWS( player1.drive(temp_city)); // need to throw beacuse the cities are not neighbors
        }
}

    //fly_charter
    for(int i=0; i<50; i++){
          player1.remove_cards();
        City temp_city = random_city(); // choose random city
        CHECK_THROWS(player1.fly_charter(temp_city)); // try to fly_charter without the city card

        player2.current_city = temp_city; //update the other player (only for comparison)
        player1.take_card(temp_city); //take card
        player1.fly_charter(temp_city); //fly to random city
        CHECK(player1.current_city == player2.current_city);
    }

    //fly shuttle
    for(int i=0; i<20; i++){
        City temp_city = random_city();
        CHECK_THROWS(player1.fly_shuttle(temp_city)); //try to fly shuttle but there are no reasearch station
    }

    for(int i=0; i<50; i++){
        City temp_city = random_city();
        board.cities_stations.at(player1.current_city) = true; // place a research station
        board.cities_stations.at(temp_city) = true; // place a research station
        player1.fly_shuttle(temp_city);
        player2.current_city = temp_city;
        CHECK(player1.current_city == player2.current_city);
    }

    board.remove_stations(); //clean the board from research stations
    
    //fly direct
    for(int i=0; i<50; i++){
         player1.remove_cards();
         City temp_city = random_city();
         CHECK_THROWS(player1.fly_direct(temp_city)); // try to fly direct but dont have card
         player1.take_card(temp_city);
         CHECK_NOTHROW(player1.fly_direct(temp_city)); // fly direct with currect card
         CHECK(contains_card(player1,temp_city) == false); // dont have this card anymore - already used
    }

    //build func
    for(int i=0; i<50; i++){
         player1.remove_cards();
         CHECK_THROWS(player1.build()); // try to build but dont have card
         City temp_city = random_city();
         player1.take_card(temp_city);
         CHECK_NOTHROW(player1.build()); // try to build with currect card
         CHECK(contains_card(player1,temp_city) == false); // dont have this card anymore - already used
    }
    
    //clean board
     board.remove_stations();
     player1.remove_cards();    

    //discover_cure
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        board.cities_stations.at(temp_city) = true; //place a station in random city
        player1.take_card(temp_city);
        player1.fly_direct(temp_city);//update current city that player1 is in
        player1.take_card(temp_city) //take 5 same cards
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city);
        player1.discover_cure(board.cities_color.at(temp_city));
        CHECK(contains_card(player1,temp_city) == false); //already used
        player1.take_card(temp_city) //take 5 same cards
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city);
        player1.discover_cure(board.cities_color.at(temp_city)); // discover cure second time
        CHECK(contains_card(player1,temp_city) == true); //beacuse this cure is already discovered
        CHECK(player1.cards.size() == 5); //check all the cards in the hand player

        player1.remove_cards(); // clean hand player
        board.remove_cures(); //clean board from cures
    }

    //clean board + clean hand player
    board.remove_stations();
    board.remove_cures();
    player1.remove_cards();

    //treat
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        player1.take_card(temp_city);
        player1.fly_direct(temp_city);//update current city that player1 is in
        CHECK_THROWS(player1.treat(temp_city)); //beacuse the board is clean - (level disease =0)

        const int level_disease = random_level_disease(); // 1-4
        board[temp_city] = level_disease; //use operator []
        CHECK_NOTHROW(player1.treat(temp_city));
        CHECK(board.sick_cities.at(temp_city) == level_disease-1); //check that the map of sick_cities update

        board[temp_city] = level_disease;
        player1.take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city); //6 cards (same city) - 1 for build , 5 for discover cure
        player1.build();
        player1.discover_cure(board.cities_color.at(temp_city));
        CHECK_NOTHROW(player1.treat(temp_city)); //legal action
        CHECK(board.sick_cities.at(temp_city) == 0); //beacuse player1 discover cure before treat

        //clean all for the next iteration
        board.remove_stations();
        board.remove_cures();
        player1.remove_cards();
    }
}
    /* check the override functions in all class */

TEST_CASE("OperationsExpert"){ //fly direct
    Board board;
    OperationsExpert player(board,random_city());

    for(int i=0; i<50; i++){
        City temp_city = random_city();
        player.take_card(temp_city); //take card for fly_direct
        player.fly_direct(temp_city); //update current city 

        player.take_card(player.current_city); //take same card
        player.build();
        CHECK(contains_card(player,player.current_city) == true); //still have this city card 
        CHECK(there_is_station(board,player.current_city) == true); // after build need to be station in this city
        player.remove_cards(); // clean the hands player
        board.remove_stations();//clean the board from reaserch stations
    }
}

TEST_CASE("Dispatcher"){
    Board board;
    Dispatcher player(board,random_city());
    //fly direct
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        player.take_card(player.current_city); // take a card on the current city
        player.build(); // build research station
        CHECK_NOTHROW(player.fly_direct(temp_city)); // fly direct - no matter if has card
        CHECK(player.current_city == temp_city); //checking if the fly was successful

        player.remove_cards(); //clean player hand
        board.remove_stations(); //clean reaserch stations
    }
}


TEST_CASE("Scientist"){
    Board board;
    int n = rand()%5; // 0-4
    Scientist player(board,random_city(),n);

     for(int i=0; i<50; i++){
        player.remove_cards(); //clean player hand
        board.remove_stations(); //clean reaserch stations
        City temp_city = random_city();
        board.cities_stations.at(temp_city) = true; //place a station in random city
        player.take_card(temp_city);
        player.fly_direct(temp_city);//update current city that player is in
        for(int i=0; i<n; i++){
        player.take_card(temp_city); //take n same cards
        }
        player.discover_cure(board.cities_color.at(temp_city));
        CHECK(contains_card(player,temp_city) == false); //already used
        
        for(int i=0; i<n; i++){
        player.take_card(temp_city); //take n same cards
        }
        player.discover_cure(board.cities_color.at(temp_city)); // discover cure second time
        CHECK(contains_card(player,temp_city) == true); //beacuse this cure is already discovered
        CHECK(player.cards.size() == n); //check all the cards from type "temp_city" in the hand player

    }
}


TEST_CASE("Researcher"){
    Board board;
    Researcher player(board,random_city());
    board.remove_stations(); //clean reaserch stations

     for(int i=0; i<50; i++){
        player.remove_cards(); //clean player hand
        City temp_city = random_city();
        player.take_card(temp_city);
        player.fly_direct(temp_city);//update current city that player is in
        player.take_card(temp_city) //take 5 same cards
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city);
        CHECK_NOTHROW(player.discover_cure(board.cities_color.at(temp_city))); //beacuse player = Researcher
        CHECK(contains_card(player,temp_city) == false); //already used
        
        player.take_card(temp_city) //take 5 same cards
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city);
        player.discover_cure(board.cities_color.at(temp_city)); // discover cure second time
        CHECK(contains_card(player,temp_city) == true); //beacuse this cure is already discovered
        CHECK(player.cards.size() == 5); //check all the cards from type "temp_city" in the hand player
        }
}


TEST_CASE("Medic"){
    Board board;
    Medic player(board,random_city());
    //treat
    for(int i=0; i<50; i++){
         //clean board and hand player
        board.remove_stations();
        board.remove_cures();
        player.remove_cards();

        City temp_city = random_city();
        player.take_card(temp_city);
        player.fly_direct(temp_city);//update current city that player is in
        CHECK_THROWS(player.treat(temp_city)); //beacuse the board is clean - (level disease =0)

        const int level_disease = random_level_disease(); // 1-4
        board[temp_city] = level_disease; //use operator []
        CHECK_NOTHROW(player.treat(temp_city));
        CHECK(board.sick_cities.at(temp_city)== 0); //check that the map of sick_cities update for Medic player

        player.take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city); //6 cards (same city) - 1 for build , 5 for discover cure
        player.build();
        player.discover_cure(board.cities_color.at(temp_city));
        CHECK_NOTHROW(player.treat(temp_city)); //legal action
        CHECK(board.sick_cities.at(temp_city) == 0); //works the same with or without cure discovery
        
    }
}


TEST_CASE("Virologist"){
    Board board;
    Virologist player(board,random_city());


    //treat
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        player.current_city = random_city(); //update city that player is in - other city from temp_city
        CHECK_THROWS(player.treat(temp_city)); //beacuse the board is clean - (level disease =0)

        const int level_disease = random_level_disease(); // 1-4
        board[temp_city] = level_disease; //use operator []
        CHECK_NOTHROW(player.treat(temp_city)); //Virologist can treat disease from other city
        CHECK(board.sick_cities.at(temp_city) == level_disease-1); //check that the map of sick_cities update

        board[temp_city] = level_disease; 
        player.take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city); //6 cards (same city) - 1 for build , 5 for discover cure
        player.build();
        player.discover_cure(board.cities_color.at(temp_city));
        CHECK_NOTHROW(player.treat(temp_city)); //legal action
        CHECK(board.sick_cities.at(temp_city) == 0); //beacuse player discover cure before treat
    }
}


TEST_CASE("GeneSplicer"){
    Board board;
    GeneSplicer player(board,random_city());

    //discover_cure
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        board.cities_stations.at(temp_city) = true; //place a station in random city
        player.take_card(temp_city);
        player.fly_direct(temp_city);//update current city that player is in
        player.take_card(random_city()) //take 5 random cards
        .take_card(random_city())
        .take_card(random_city())
        .take_card(random_city())
        .take_card(random_city());
        player.discover_cure(board.cities_color.at(temp_city)); // GeneSplicer ability - can discover_cure with 5 different cards
        CHECK(contains_card(player,temp_city) == false); //already used
        player.take_card(temp_city) //take 5 random cards
        .take_card(random_city())
        .take_card(random_city())
        .take_card(random_city())
        .take_card(random_city());
        player.discover_cure(board.cities_color.at(temp_city)); // discover cure second time in the same city - same color
        CHECK(contains_card(player,temp_city) == true); //beacuse this cure is already discovered
        CHECK(player.cards.size() == 5); //check all the cards in the hand player

        player.remove_cards(); // clean hand player
        board.remove_cures(); //clean board from cures
    }
}


TEST_CASE("FieldDoctor"){
    Board board;
    FieldDoctor player(board,random_city());

    //treat
    for(int i=0; i<50; i++){
        City temp_city = random_city();
        player.take_card(temp_city);
        player.fly_direct(temp_city);//update current city that player is in
        City neighbor_city = random_city();
        if(board.cities_and_neighbors.at(temp_city).at(neighbor_city)){player.drive(neighbor_city);}
        CHECK_THROWS(player.treat(temp_city)); //beacuse the board is clean - (level disease =0)

        const int level_disease = random_level_disease(); // 1-4
        board[temp_city] = level_disease; //use operator []
        CHECK_NOTHROW(player.treat(temp_city)); //legal action
        CHECK(board.sick_cities.at(temp_city) == level_disease-1); //check that the map of sick_cities update

        board[temp_city] = level_disease;
        player.take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city)
        .take_card(temp_city); //6 cards (same city) - 1 for build , 5 for discover cure
        player.build();
        player.discover_cure(board.cities_color.at(temp_city));
        CHECK_NOTHROW(player.treat(temp_city)); //legal action
        CHECK(board.sick_cities.at(temp_city) == 0); //beacuse player discover cure before treat

        //clean board + hand player
        player.remove_cards();
        board.remove_cures();
        board.remove_stations();
    }
}