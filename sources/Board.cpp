#include "Board.hpp"
using namespace std;
namespace pandemic{

  /* constractor */
  Board::Board(){
    //init cities
    sick_cities = {{City::Algiers,{}},{City::Atlanta,{}},{City::Baghdad,{}},{City::Bangkok,{}},{City::Beijing,{}},
      {City::Bogota,{}},{City::BuenosAires,{}},{City::Cairo,{}},{City::Chennai,{}},{City::Chicago,{}},
      {City::Delhi,{}},{City::Essen,{}},{City::HoChiMinhCity,{}},{City::HongKong,{}},{City::Istanbul,{}},
      {City::Jakarta,{}},{City::Johannesburg,{}},{City::Karachi,{}},{City::Khartoum,{}},{City::Kinshasa,{}},
      {City::Kolkata,{}},{City:: Lagos,{}},{City::Lima,{}},{City:: London,{}},{City::LosAngeles,{}},
      {City::Madrid,{}},{City::Manila,{}},{City::MexicoCity,{}},{City:: Miami,{}},{City::Milan,{}},
      {City::Montreal,{}},{City::Moscow,{}},{City::Mumbai,{}},{City::NewYork,{}},{City::Osaka,{}},
      {City::Paris,{}},{City::Riyadh,{}},{City::SanFrancisco,{}},{City::Santiago,{}},{City::SaoPaulo,{}},
      {City::Seoul,{}},{City::Shanghai,{}},{City::StPetersburg,{}},{City::Sydney,{}},{City::Taipei,{}},
      {City::Tehran,{}},{City::Tokyo,{}},{City::Washington,{}}};
    
    cities_color = {{City::Algiers,Color::Black},{City::Atlanta,Color::Blue},{City::Baghdad,Color::Black},{City::Bangkok,Color::Red},
      {City::Beijing,Color::Red},{City::Bogota,Color::Yellow},{City::BuenosAires,Color::Yellow},{City::Cairo,Color::Black},
      {City::Chennai,Color::Red},{City::Chicago,Color::Blue},{City::Delhi,Color::Black},{City::Essen,Color::Blue},
      {City::HoChiMinhCity,Color::Red},{City::HongKong,Color::Red},{City::Istanbul,Color::Black},{City::Jakarta,Color::Red},
      {City::Johannesburg,Color::Yellow},{City::Karachi,Color::Black},{City::Khartoum,Color::Yellow},{City::Kinshasa,Color::Yellow},
      {City::Kolkata,Color::Red},{City:: Lagos,Color::Yellow},{City::Lima,Color::Yellow},{City::London,Color::Blue},
      {City::LosAngeles,Color::Yellow},{City::Madrid,Color::Blue},{City::Manila,Color::Red},{City::MexicoCity,Color::Yellow},
      {City:: Miami,Color::Blue},{City::Milan,Color::Yellow},{City::Montreal,Color::Blue},{City::Moscow,Color::Black},
      {City::Mumbai,Color::Black},{City::NewYork,Color::Blue},{City::Osaka,Color::Red},{City::Paris,Color::Blue},
      {City::Riyadh,Color::Black},{City::SanFrancisco,Color::Blue},{City::Santiago,Color::Yellow},{City::SaoPaulo,Color::Yellow},
      {City::Seoul,Color::Red},{City::Shanghai,Color::Red},{City::StPetersburg,Color::Blue},{City::Sydney,Color::Red},
      {City::Taipei,Color::Red},{City::Tehran,Color::Black},{City::Tokyo,Color::Red},{City::Washington,Color::Blue}};
    
    cities_and_neighbors = {{City::Algiers,{}},{City::Atlanta,{}},{City::Baghdad,{}},{City::Bangkok,{}},{City::Beijing,{}},
      {City::Bogota,{}},{City::BuenosAires,{}},{City::Cairo,{}},{City::Chennai,{}},{City::Chicago,{}},
      {City::Delhi,{}},{City::Essen,{}},{City::HoChiMinhCity,{}},{City::HongKong,{}},{City::Istanbul,{}},
      {City::Jakarta,{}},{City::Johannesburg,{}},{City::Karachi,{}},{City::Khartoum,{}},{City::Kinshasa,{}},
      {City::Kolkata,{}},{City:: Lagos,{}},{City::Lima,{}},{City:: London,{}},{City::LosAngeles,{}},
      {City::Madrid,{}},{City::Manila,{}},{City::MexicoCity,{}},{City:: Miami,{}},{City::Milan,{}},
      {City::Montreal,{}},{City::Moscow,{}},{City::Mumbai,{}},{City::NewYork,{}},{City::Osaka,{}},
      {City::Paris,{}},{City::Riyadh,{}},{City::SanFrancisco,{}},{City::Santiago,{}},{City::SaoPaulo,{}},
      {City::Seoul,{}},{City::Shanghai,{}},{City::StPetersburg,{}},{City::Sydney,{}},{City::Taipei,{}},
      {City::Tehran,{}},{City::Tokyo,{}},{City::Washington,{}}};
  }

  int& Board::operator[](City city){
    return this->sick_cities.at(city);
  }

  int Board::operator[](City city)const{
    return this->sick_cities.at(city);
  }

  std::ostream& operator<<(std::ostream& os ,const Board& board){    
    return (os << " stam" << std::endl);//////////////////////////****************////////////////// need to fix//////////////
  }


  /*reminder:
  it-->first gives you the key (City)
  it->second gives you the mapped element (int) */
  bool Board::is_clean(){
    bool ans = true;
    for (std::map<City, int>::const_iterator it = sick_cities.begin(); it != sick_cities.end(); ++it){
      if(it->second != 0){
        ans = false;
        break;
      }
    }
    return ans;
  }

  void Board::remove_cures(){
    this->discovered_cures.clear();
  }

  void Board::remove_stations(){
    this->cities_stations.clear();
  }

  Color Board::which_color(City city){
         return this->cities_color.at(city);
    }

  bool Board::exists_cure(Color color){
    bool ans = false;
    for(const Color c : this->discovered_cures){ 
      if(c == color){
        ans = true;
        break;
      }
    }
    return ans;
  }

  bool Board::exists_station(City city){
    bool ans = false;
    for(const City c:this->cities_stations){
      if(city == c){
        ans = true;
        break;
      }
    }
    return ans;
    }

  void Board::build_station(City city){
    this->cities_stations.insert(city);
  }

  Color Board::get_color(City city){
    return this->cities_color.at(city);
  }

  void Board::new_cure_discovered(Color color){
    this->discovered_cures.insert(color);
  }

  int Board::level_disese_in_the_city(City city){
    return this->sick_cities.at(city);
   }

   bool Board::is_neighbors(City city1 , City city2){
      bool ans = false;
      for(const City c: this->cities_and_neighbors.at(city1)){
        if(c == city2){
          ans = true;
          break;
        }
      }
      return ans;
   }

}