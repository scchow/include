#ifndef BAR_H_
#define BAR_H_

#include <iostream>
#include <vector>
#include <math.h>

using std::vector ;

class Bar{
  public:
    Bar(size_t c): capacity(c){
      padOccupancy = 0;
    }

    Bar(size_t c, int padding): capacity(c), padOccupancy(padding){
    }

    ~Bar(){}
    
    double GetReward(int nAgents, bool update=false){
      numAgents = nAgents ;
      useUpdated = update ;
      
      if (update)
        reward = Bar::ClassicCongestion(nAgents);
      else
        reward = Bar::UpdatedCongestion(nAgents);

      return reward ;
    }
    
    int GetCapacity(){return capacity ;}
  private:
    int capacity ;
    bool useUpdated ;
    int numAgents ;
    double reward ;
    int padOccupancy; /// pad occupancy with this number of agents 

    void (Bar::*EnjoymentFunction)() ;
    double ClassicCongestion(int occupancy){
      int paddedOccupancy = occupancy + padOccupancy;
      return (double)capacity * exp(-0.1 * pow((double)paddedOccupancy-(double)capacity,2)) ;
//      std::cout << "Attendance: " << numAgents << ", total enjoyment: " << r << "\n" ;
    }
    
    double UpdatedCongestion(int occupancy){ // currently the same, will update when we get to including "celebrity" agents
      int paddedOccupancy = occupancy + padOccupancy;
      return (double)capacity * exp(-0.1 * pow((double)paddedOccupancy-(double)capacity,2)) ;
    }
} ;

#endif // BAR_H_
