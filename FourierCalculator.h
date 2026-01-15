#ifndef FOURIER_CALCULATOR_H
#define FOURIER_CALCULATOR_H

#include <cmath>
#include <cstdio>
#include <math.h>

class MathFunc 
{
    public:
        MathFunc();

        virtual double Calculate(double x) const = 0;
        double Integrate() const;
        void DFT(int n) const;
        virtual MathFunc* Clone() const = 0;
        
        virtual ~MathFunc();
};

class StepFunc : public MathFunc 
{
    public:
        StepFunc();

        virtual double Calculate(double x) const;
        virtual MathFunc* Clone() const;

        virtual ~StepFunc();
};

class SinFunc : public MathFunc 
{
    int n;

    public:
        SinFunc(int n);

        virtual double Calculate(double x) const;
        virtual MathFunc* Clone() const;
        
        virtual ~SinFunc();
};

class CosFunc : public MathFunc 
{
    int n;

    public:
        CosFunc(int n);

        virtual double Calculate(double x) const;
        virtual MathFunc* Clone() const;

        virtual ~CosFunc();
};

class MultiFunc : public MathFunc
{
    MathFunc* a;
    MathFunc* b;

public:
    MultiFunc(const MathFunc& a, const MathFunc& b);

    MultiFunc(const MultiFunc& other);
    MultiFunc& operator=(const MultiFunc& other);

    virtual double Calculate(double x) const;
    virtual MathFunc* Clone() const;
    virtual ~MultiFunc();
};

MultiFunc operator*(const MathFunc& lhs, const MathFunc& rhs);


#endif

