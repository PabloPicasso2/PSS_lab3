#ifndef PI_H
#define PI_H

#include "../siso/siso.hpp"

/**
 * @brief 
 * 
 */
class PI : virtual public SISO
{
public:
    PI(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5);
    ~PI() = default;
    
    virtual double simulate(double pv) override;

    virtual double calc_error(double pv, double set_point);
    virtual double calc_prop(double error);
    virtual double calc_integr(double error);
    virtual void set_setPoint(double sp);
    // double calc_output(double pv, double set_point) override;

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
