#ifndef FOURIER_CALCULATOR_H
#define EXAM_RESULTS_H

#include <iostream>
#include <math.h>
#include <string.h>

class MathFunc {
    public:
        MathFunc();
            virtual double Calculate(double x) const = 0;
            double Integrate() const;
            void DFT(int n) const;
            virtual MathFunc* Clone() const = 0;
            virtual ~MathFunc();
 };  

class StepFunc: public MathFunc {
    public:
        StepFunc();
        virtual double Calculate(double x);
        virtual MathFunc* Clone();
        virtual ~StepFunc();
};

class SinFunc: public MathFunc {
    public:
        SinFunc(int n);
        virtual double Calculate(double x);
        virtual MathFunc* Clone();
        virtual ~SinFunc();
};

class CosFunc: public MathFunc {
    public:
        CosFunc(int n);
        virtual double Calculate(double x);
        virtual MathFunc* Clone();
        virtual ~CosFunc();
};

class MultiFunc: public MathFunc {
    public:
        MultiFunc(MathFunc& a, MathFunc& b);
        virtual double Calculate(double x);
        virtual MathFunc* Clone();
        virtual ~MultiFunc();
};

#endif