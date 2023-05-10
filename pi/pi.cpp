#include "pi.hpp"
#include <cmath>

/**
 * @brief Construct a new PI::PI object
 * 
 * @param min minimum controller output
 * @param max maximum controller output
 * @param dt time step
 * @param kp proportional coef
 * @param ki integral coef
 */
PI::PI(double min, double max, double dt, double kp, double ki)
{
    m_dt = dt;
    m_Kp = kp;
    m_Ki = ki;
    m_min = min;
    m_max = max;
    integral_temp = 0.0;
    prev_error = 0.0;
}

// calculate error
double PI::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

// calculate proportional term
double PI::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

// calculate integral term
double PI::calc_integr(double error)
{
    integral_temp += error * m_dt;
    double integr = m_Ki * integral_temp;
    return integr;
}

void PI::set_setPoint(double sp)
{
    set_point = sp;
}

double PI::simulate(double pv)
{
    // Calculate controller output
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double integr = calc_integr(error);
    double output = prop + integr;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}
