#ifndef PID_H
#define PID_H

#include "../pd/pd.hpp"
#include "../pi/pi.hpp"

class PID : public PD, public PI
{
public:
    PID(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5, double kd = 0.05);
    ~PID() = default;

    double calc_error(double pv, double set_point) override;
    double calc_prop(double error) override;
    double calc_integr(double error) override;
    double calc_deriv(double error) override;
    void set_setPoint(double sp) override;
    double simulate(double pv) override;

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
