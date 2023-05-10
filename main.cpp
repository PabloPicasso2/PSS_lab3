#include "pi/pi.hpp"
#include "pd/pd.hpp"
#include <iostream>
#include "arx/arx.hpp"
#include "pid/pid.hpp"

/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
    auto pi = PI(0.0, 10.0, 1.0, 1.0, 2.0);
    auto arx = ARX({1.0, 0.5}, {-0.5}, 1, 0);
    arx.save("config.csv");
    pi.set_setPoint(1.0);

    // closed loop PID simulation for y=0 = const
    std::cout << "closed loop PID simulation \n";
    std::cout << "u" << "\t" << "y" << "\n";
    double y = 0.0;
    for (int i = 0; i < 30; i++)
    {
        auto u = pi.simulate(y);
        std::cout << u << "\t" << y << "\n";
    }

/*
    // closed loop ARX-PI simulation 
    std::cout << "\n\nclosed loop ARX-PI simulation \n";
    std::cout << "u" << "\t" << "y" << "\n";
    y = 0.0;
    for (int i = 0; i < 30; i++)
    {
        auto u = pi.simulate(y);
        y = arx.simulate(u);
        std::cout << u << "\t" << y << "\n";
    }
*/

    std::cin.get();
}
