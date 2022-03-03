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

void StatsAlerter::checkAndAlert(const std::vector<float>&InputValues)
{
    for(auto i = InputValues.begin();i != InputValues.end();i++)
    {
        if(*i > Max_value)
        {
            for(unsigned int j = 0;j < Alert.size(); j++)
            {
                Alert[j]->alertsystem();
            }
            break;
        }
    }
}
    
