#include "stats.h"
#include <math.h>


Stats Statistics::ComputeStatistics(const std::vector<float>&R) {
    //Implement statistics here
	
    Stats obj;
    int Size = R.size();
    
    if(Size != 0)
    {
        obj.min = obj.max = R[0];
        obj.average = 0;
        for(auto x = R.begin(); x != R.end(); x++)
        {
          if(*x < obj.min)
          {
            obj.min = *x;
          }
          if(*x > obj.max)
          {
            obj.max = *x;
          }
          obj.average = obj.average + *x;
        }
	obj.average = obj.average/Size ;
    } 
    else
    {
      obj.average = NAN;
      obj.min = NAN;
      obj.max = NAN;
    }
    
    return obj;
}

void StatsAlerter::checkAndAlert(const std::vector<float>&Readings)
{
    float max = Readings[0];
    //EmailAlert e_obj;
    //LEDAlert l_obj;
    for(auto x = Readings.begin(); x != Readings.end(); x++)
    {
	if(*x > max)
        {
            max = *x;
        }
    }
    if(max > thersholdvalue)
    {
	    //e_obj.alert();
	    //l_obj.alert();
        for(int y = 0; y < Alert.size(); y++)
        {
            Alert[y].alert();
        }
    }
}
    
