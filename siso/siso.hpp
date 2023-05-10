#ifndef SISO_H
#define SISO_H

/**
 * @brief 
 * 
 */
class SISO
{
public:
    SISO() = default;
    virtual ~SISO() = default;

    virtual double simulate(double x) = 0;
};

#endif
