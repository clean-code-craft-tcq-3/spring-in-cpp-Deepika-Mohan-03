#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& R) {

    Stats obj;
    obj.min = obj.max = R[0];
    obj.average = 0;
    int Size = R.size();
    
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
    obj.average = obj.average/Size ;
    
    return obj;
}
