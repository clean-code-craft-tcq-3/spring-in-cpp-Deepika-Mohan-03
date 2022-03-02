class Stats
{
   public:
    float min, max, average;
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&R);
}
