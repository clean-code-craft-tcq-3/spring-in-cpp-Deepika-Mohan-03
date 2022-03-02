class Stats
{
   public:
    float min, max, average;
};

class IAlerter
{
   public:
   virtual void alert() = 0;
};

class EmailAlert:public IAlerter
{
    public:
    void alert();
    bool emailsent = 0;
};

class LEDGlow:public IAlerter
{
     public:
     void alert();
     bool LEDGlow = 0;
};

class StatsAlerter:public EmailAlert,public LEDGlow
{
     public:
     float thersholdvalue;
     void checkAndAlert(std::vector<float>&);
     StatsAlerter(float T_V, std::vector<IAlerter*>&Alert)
     {
         thersholdvalue = T_V;
     }
};
     
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&R);
}
