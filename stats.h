class Stats
{
   public:
    float min, max, average;
};
class IAlerter{
public:
    virtual void alertsystem() = 0;
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&R);
}
