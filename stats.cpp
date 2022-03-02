#include "stats.h"
#include <math.h>

#define INT_NULL ((int)0)

Stats Statistics::ComputeStatistics(const std::vector<float>&g ) {
    //Implement statistics here
    Stats tempstats;
    float Max,Min,avg = 0;
    int Maxsize = g.size();
    
    if(Maxsize != INT_NULL)
    {
    Max = Min = g[0];
    for(auto i= g.begin();i != g.end(); i++)
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
    
    avg = avg/Maxsize;
    tempstats.average = avg;
    tempstats.min = Min;
    tempstats.max = Max;
   
    }
    else
    {
    tempstats.average = NAN;
    tempstats.min = NAN;
    tempstats.max = NAN;
    }
    
    return tempstats;
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
