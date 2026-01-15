#include "FourierCalculator.h"

// MathFunc
MathFunc::MathFunc() {}
MathFunc::~MathFunc() {}

double MathFunc::Integrate() const
{
    int N = 200000;
    double sum = 0.0;
    double h = 1.0 / N;

    for (int i = 0; i < N; i++)
    {
        double x = i * h;
        sum += Calculate(x);
    }

    return sum * h;
}

void MathFunc::DFT(int N) const
{
    std::printf("%i %.3f %.3f\n", 0, 0.0, Integrate());

    for (int n = 1; n <= N; n++)
    {
        SinFunc s(n);
        CosFunc c(n);

        double An = 2.0 * ((*this) * s).Integrate();
        double Bn = 2.0 * ((*this) * c).Integrate();

        std::printf("%i %.3f %.3f\n", n, An, Bn);
    }
}



StepFunc::StepFunc() {}
StepFunc::~StepFunc() {}

double StepFunc::Calculate(double x) const
{
    if (x < 0.5) return -1.0;
    else return 1.0;
}

MathFunc* StepFunc::Clone() const
{
    return new StepFunc();
}



SinFunc::SinFunc(int nn) : n(nn) {}
SinFunc::~SinFunc() {}

double SinFunc::Calculate(double x) const
{
    return std::sin(2.0 * M_PI * n * x);
}

MathFunc* SinFunc::Clone() const
{
    return new SinFunc(n);
}



CosFunc::CosFunc(int nn) : n(nn) {}
CosFunc::~CosFunc() {}

double CosFunc::Calculate(double x) const
{
    return std::cos(2.0 * M_PI * n * x);
}

MathFunc* CosFunc::Clone() const
{
    return new CosFunc(n);
}



MultiFunc::MultiFunc(const MathFunc& aa, const MathFunc& bb)
{
    a = aa.Clone();
    b = bb.Clone();
}

MultiFunc::MultiFunc(const MultiFunc& other)
{
    a = other.a->Clone();
    b = other.b->Clone();
}

MultiFunc& MultiFunc::operator=(const MultiFunc& other)
{
    if (this == &other) return *this;

    delete a;
    delete b;

    a = other.a->Clone();
    b = other.b->Clone();

    return *this;
}

MultiFunc::~MultiFunc()
{
    delete a;
    delete b;
}

double MultiFunc::Calculate(double x) const
{
    return a->Calculate(x) * b->Calculate(x);
}

MathFunc* MultiFunc::Clone() const
{
    return new MultiFunc(*a, *b);
}

MultiFunc operator*(const MathFunc& lhs, const MathFunc& rhs)
{
    return MultiFunc(lhs, rhs);
}
