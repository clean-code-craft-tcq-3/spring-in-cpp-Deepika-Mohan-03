#include <vector> 

class Stats
{
   public:
    float min;
    float max;
    float average;
};

class IAlerter
{
   public:
   virtual void alert() = 0;
};

class EmailAlert:public IAlerter
{
    public:
    bool emailsent = 0;
    void alert()
    {
        emailSent = 1;
    }
};

class LEDGlow:public IAlerter
{
     public:
     bool LEDGlow = 0;
     void alert()
     {
         LEDGlow = 1;
     }
};

class StatsAlerter:public IAlerter
{
     public:
     float thersholdvalue;
     std::vector<IAlerter*> Alert;
     void checkAndAlert(const std::vector<float>& );
     StatsAlerter(const float &T_V,std::vector<IAlerter*> &A)
     {
         thersholdvalue = T_V;
         Alert A;
     }
};
     
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&R);
}
