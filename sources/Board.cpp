#include "Board.hpp"
using namespace std;
namespace pandemic{

  /* constractor */
  Board::Board(){
    //init cities
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
      {City::Chennai,Color::Black},{City::Chicago,Color::Blue},{City::Delhi,Color::Black},{City::Essen,Color::Blue},
      {City::HoChiMinhCity,Color::Red},{City::HongKong,Color::Red},{City::Istanbul,Color::Black},{City::Jakarta,Color::Red},
      {City::Johannesburg,Color::Yellow},{City::Karachi,Color::Black},{City::Khartoum,Color::Yellow},{City::Kinshasa,Color::Yellow},
      {City::Kolkata,Color::Red},{City:: Lagos,Color::Yellow},{City::Lima,Color::Yellow},{City::London,Color::Blue},
      {City::LosAngeles,Color::Yellow},{City::Madrid,Color::Blue},{City::Manila,Color::Red},{City::MexicoCity,Color::Yellow},
      {City:: Miami,Color::Blue},{City::Milan,Color::Blue},{City::Montreal,Color::Blue},{City::Moscow,Color::Black},
      {City::Mumbai,Color::Black},{City::NewYork,Color::Blue},{City::Osaka,Color::Red},{City::Paris,Color::Blue},
      {City::Riyadh,Color::Black},{City::SanFrancisco,Color::Blue},{City::Santiago,Color::Yellow},{City::SaoPaulo,Color::Yellow},
      {City::Seoul,Color::Red},{City::Shanghai,Color::Red},{City::StPetersburg,Color::Blue},{City::Sydney,Color::Red},
      {City::Taipei,Color::Red},{City::Tehran,Color::Black},{City::Tokyo,Color::Red},{City::Washington,Color::Blue}};

    cities_and_neighbors = {{City::Algiers,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}
      ,{City::Atlanta,{City::Chicago, City::Miami, City::Washington}}
      ,{City::Baghdad,{ City::Tehran ,City::Istanbul ,City::Cairo, City::Riyadh ,City::Karachi}}
      ,{City::Bangkok,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}
      ,{City::Beijing,{City::Shanghai, City::Seoul}}
      ,{City::Bogota,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}
      ,{City::BuenosAires,{ City::Bogota, City::SaoPaulo}}
      ,{City::Cairo,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}
      ,{City::Chennai,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok ,City::Jakarta}}
      ,{City::Chicago,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}
      ,{City::Delhi,{City::Tehran, City::Karachi, City::Mumbai ,City::Chennai, City::Kolkata}}
      ,{City::Essen,{City::London, City::Paris, City::Milan, City::StPetersburg}}
      ,{City::HoChiMinhCity,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}
      ,{City::HongKong,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}
      ,{City::Istanbul,{City::Milan, City::Algiers ,City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}
      ,{City::Jakarta,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}
      ,{City::Johannesburg,{City::Kinshasa, City::Khartoum}}
      ,{City::Karachi,{City::Tehran ,City::Baghdad ,City::Riyadh, City::Mumbai, City::Delhi}}
      ,{City::Khartoum,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}
      ,{City::Kinshasa,{City::Lagos, City::Khartoum, City::Johannesburg}}
      ,{City::Kolkata,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}
      ,{City:: Lagos,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}
      ,{City::Lima,{City::MexicoCity, City::Bogota, City::Santiago}}
      ,{City:: London,{City::NewYork, City::Madrid, City::Essen, City::Paris}}
      ,{City::LosAngeles,{City::SanFrancisco, City::Chicago ,City::MexicoCity, City::Sydney}}
      ,{City::Madrid,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}
      ,{City::Manila,{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney,City::HongKong}}
      ,{City::MexicoCity,{City::LosAngeles, City::Chicago, City::Miami, City::Lima ,City::Bogota}}
      ,{City:: Miami,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}
      ,{City::Milan,{City::Essen, City::Paris, City::Istanbul}}
      ,{City::Montreal,{City::Chicago, City::Washington, City::NewYork}}
      ,{City::Moscow,{City::StPetersburg, City::Istanbul, City::Tehran}}
      ,{City::Mumbai,{City::Karachi, City::Delhi, City::Chennai}}
      ,{City::NewYork,{City::Montreal, City::Washington ,City::London, City::Madrid}}
      ,{City::Osaka,{City::Taipei, City::Tokyo}}
      ,{City::Paris,{City::Algiers, City::Essen, City::Madrid, City::Milan ,City::London}}
      ,{City::Riyadh,{City::Baghdad, City::Cairo, City::Karachi}}
      ,{City::SanFrancisco,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}
      ,{City::Santiago,{City::Lima}}
      ,{City::SaoPaulo,{City::Bogota, City::BuenosAires, City::Lagos ,City::Madrid}}
      ,{City::Seoul,{City::Beijing, City::Shanghai, City::Tokyo}}
      ,{City::Shanghai,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}
      ,{City::StPetersburg,{City::Essen, City::Istanbul, City::Moscow}}
      ,{City::Sydney,{City::Jakarta, City::Manila, City::LosAngeles}}
      ,{City::Taipei,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}
      ,{City::Tehran,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}
      ,{City::Tokyo,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}
      ,{City::Washington,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};

      cities_stations = {};
      discovered_cures = {};
  }

  int& Board::operator[](City city){
    return this->sick_cities.at(city);
  }

  std::ostream& operator<<(std::ostream& os ,const Board& board){    
    return (os << " stam" << std::endl);//////////////////////////****************////////////////// need to fix//////////////
  }


  /*reminder:
  pair.first gives you the key (City)
  pair.second gives you the mapped element (int) */
  bool Board::is_clean(){
    bool ans = true;
    for(const pair<City,int> pair:this->sick_cities){
      if(pair.second != 0){
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