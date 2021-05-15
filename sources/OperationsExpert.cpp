#include "OperationsExpert.hpp"
namespace pandemic{
    
    void OperationsExpert::build(){
         bool ans = this->board.exists_station(this->current_city);
         if(!ans){
             //if no exists already research station in the current city
             this->board.build_station(this->current_city);
         }
    }
}