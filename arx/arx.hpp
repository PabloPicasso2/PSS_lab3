#ifndef ARX_H
#define ARX_H

#include "../siso/siso.hpp"
#include <vector>
#include <deque>
#include <string>

/**
 * @brief 
 * 
 */
class ARX : public SISO
{
public:
    using vector = std::vector<double>;
    using state = std::deque<double>;

    /**
     * @brief Construct a new ARX object
     *
     * @param a
     * @param b
     * @param k
     * @param evar
     */
    ARX(const vector &a, const vector &b, unsigned k = 0, double evar = 0.0);
    ~ARX() = default;

    double simulate(double x) override;
    void save(const std::string &path);

private:
    vector m_a, m_b;
    state m_x, m_y;
    double m_evar;
    unsigned m_k, m_x_depth, m_y_depth;

    void create_states();
    void update_state(state &state, double new_state);
};

#endif
