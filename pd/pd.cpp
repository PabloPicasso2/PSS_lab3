#include "pd.hpp"
#include <cmath>

/**
 * @brief Construct a new PD::PD object
 *
 * @param min minimum controller output
 * @param max maximum controller output
 * @param dt time step
 * @param kp proportional coef
 * @param kd derivative coef
 */
PD::PD(double min, double max, double dt, double kp, double kd)
{
    m_dt = dt;
    m_Kp = kp;
    m_Kd = kd;
    m_min = min;
    m_max = max;
}

// calculate error
double PD::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

// calculate proportional term
double PD::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

// calculate derivative term
double PD::calc_deriv(double error)
{
    double deriv = m_Kd * ((error - prev_error) / m_dt);
    // Save error to previous error
    prev_error = error;

    return deriv;
}

// update setpoint
void PD::set_setPoint(double sp)
{
    set_point = sp;
}

// calculate controller output
double PD::simulate(double pv)
{
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double deriv = calc_deriv(error);
    double output = prop + deriv;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}