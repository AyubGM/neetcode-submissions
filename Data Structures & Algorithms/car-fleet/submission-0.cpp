class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        std::vector<pair<int,int>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end(), [](const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.first > b.first;
        });

        std::vector<double> fleetTimes;

        for(int i = 0; i < n; i++)
        {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if(fleetTimes.empty() || time > fleetTimes.back())
            {
                fleetTimes.push_back(time);
            }
        }

        return fleetTimes.size();
    }
};
