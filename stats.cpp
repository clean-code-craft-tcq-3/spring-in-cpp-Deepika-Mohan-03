#include "stats.h"
#include <math.h>


Stats Statistics::ComputeStatistics(const std::vector<float>&R) {
    //Implement statistics here
    Stats obj;
    float Max,Min,avg = 0;
    int Size = R.size();
    
    if(Size != 0)
    {
    Max = Min = R[0];
    for(auto i = g.begin(); i != g.end(); i++)
    {
        if(Max < *i)
        {
            Max = *i;
        }
        if(Min > *i)
        {
            Min = *i;
        }
        avg = avg + *i;
    }
    
    avg = avg/Size;
    obj.average = avg;
    obj.min = Min;
    obj.max = Max;
   
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
    
