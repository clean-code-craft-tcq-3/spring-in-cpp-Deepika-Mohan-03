#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>&R) {

    Stats obj;
    obj.min = obj.max = R[0];
    obj.average = 0;
    int Size = R.size();
    
    if(Size != 0)
    {
    for(auto x : R)
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
    }
    else
    {
        obj.min = NAN;
        obj.max = NAN;
        obj.average = NAN;
    }
    obj.average = obj.average/Size ;
    
    return obj;
}

void StatsAlerter::checkAndAlert(std::vector<float>&Readings)
{
    for(auto x : Readings)
    {
        if(x > thersholdvalue)
        {
            EmailAlert e_obj;
            LEDGlow l_obj;
            e_obj.emailsent = 1;
            l_obj.LEDGlow = 1;
        }
    }
}
    
