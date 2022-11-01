#include "Board.hpp"
using namespace std;
namespace pandemic{

  /* constractor */
  Board::Board(){
    //init cities
    cities_stations = {{City::Algiers,false},{City::Atlanta,false},{City::Baghdad,false},{City::Bangkok,false},{City::Beijing,false},
      {City::Bogota,false},{City::BuenosAires,false},{City::Cairo,false},{City::Chennai,false},{City::Chicago,false},
      {City::Delhi,false},{City::Essen,false},{City::HoChiMinhCity,false},{City::HongKong,false},{City::Istanbul,false},
      {City::Jakarta,false},{City::Johannesburg,false},{City::Karachi,false},{City::Khartoum,false},{City::Kinshasa,false},
      {City::Kolkata,false},{City:: Lagos,false},{City::Lima,false},{City:: London,false},{City::LosAngeles,false},
      {City::Madrid,false},{City::Manila,false},{City::MexicoCity,false},{City:: Miami,false},{City::Milan,false},
      {City::Montreal,false},{City::Moscow,false},{City::Mumbai,false},{City::NewYork,false},{City::Osaka,false},
      {City::Paris,false},{City::Riyadh,false},{City::SanFrancisco,false},{City::Santiago,false},{City::SaoPaulo,false},
      {City::Seoul,false},{City::Shanghai,false},{City::StPetersburg,false},{City::Sydney,false},{City::Taipei,false},
      {City::Tehran,false},{City::Tokyo,false},{City::Washington,false}};
    
    sick_cities = {{City::Algiers,0},{City::Atlanta,0},{City::Baghdad,0},{City::Bangkok,0},{City::Beijing,0},
      {City::Bogota,0},{City::BuenosAires,0},{City::Cairo,0},{City::Chennai,0},{City::Chicago,0},
      {City::Delhi,0},{City::Essen,0},{City::HoChiMinhCity,0},{City::HongKong,0},{City::Istanbul,0},
      {City::Jakarta,0},{City::Johannesburg,0},{City::Karachi,0},{City::Khartoum,0},{City::Kinshasa,0},
      {City::Kolkata,0},{City:: Lagos,0},{City::Lima,0},{City:: London,0},{City::LosAngeles,0},
      {City::Madrid,0},{City::Manila,0},{City::MexicoCity,0},{City:: Miami,0},{City::Milan,0},
      {City::Montreal,0},{City::Moscow,0},{City::Mumbai,0},{City::NewYork,0},{City::Osaka,0},
      {City::Paris,0},{City::Riyadh,0},{City::SanFrancisco,0},{City::Santiago,0},{City::SaoPaulo,0},
      {City::Seoul,0},{City::Shanghai,0},{City::StPetersburg,0},{City::Sydney,0},{City::Taipei,0},
      {City::Tehran,0},{City::Tokyo,0},{City::Washington,0}};
    
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
    
    // cities_and_neighbors = need to init
  }

  Board& Board::operator[](City city){
    return *this;
  }

  const Board Board::operator[](City city)const{
    return *this;
  }

  Board& Board::operator=(int num){
    return *this;
  }

  std::ostream& operator<<(std::ostream& os ,const Board& board){
    return (os << " stam" << std::endl);
  }

  bool Board::is_clean(){
    this->sick_cities[City::Delhi] = 0; // only for tidy
    return true;
  }

  void Board::remove_cures(){

  }

  void Board::remove_stations(){
    
  }


}