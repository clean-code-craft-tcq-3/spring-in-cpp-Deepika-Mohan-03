#include <vector>

class Stats
{
public:
  float average, min, max;
};

class IAlerter{
public:
    virtual void alert() = 0;
};

class EmailAlert:public IAlerter
{
   public:
    bool emailSent = 0;
    void alert()
    {
    }
    void ealert()
    {
        emailSent = 1;
    }
};

class LEDAlert:public IAlerter
{
    public:
    bool ledGlows = 0;
    void alert()
    {
    }
     void Lalert()
    {
        ledGlows = 1;
    }
};

class StatsAlerter:public EmailAlert, public LEDAlert
{
   public:
    float thersholdvalue;
    std::vector<IAlerter*> Alert;
    
    StatsAlerter(const float &MT, std::vector<IAlerter*> &A)
    {
        thersholdvalue = MT;
        Alert = A;
    }
    
    void alert()
    {
    }
    
    void checkAndAlert(const std::vector<float>& );
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&R);
}
