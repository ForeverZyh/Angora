#include "stdio.h"
#include "Int.h"

static double EPS = 1e-1;

Int::Int (long long _val): val(_val) {
    dx = 0;
}

Int::Int (long long _val, double _dx): val(_val), dx(_dx) {
}

long long Int::get_dx(int arg_id) const {
    printf("Catch grad: %lf, when val = %lld., cmp at arg_id: %d\n", dx, val, arg_id);
    if (dx <= EPS && dx >= -EPS) return 0;
    if (dx <= 1 && dx > EPS) return 1;
    if (dx >= -1 && dx < -EPS) return -1;
    return (long long)dx;
}

Int::operator int() {
    return (int)val;
}   

Int& Int::operator =(const int& b)
{
    val = b;
    dx = 0;
    return *this;
}

Int Int::operator *(const Int&b) const {
    return Int(val * b.val, b.dx * val + dx * b.val);
}

Int Int::operator *(const int&b) const {
    return Int(val * b, dx * b);
}

Int operator *(const int&a, const Int&b) {
    return b * a;
}

Int Int::operator +(const Int&b) const {
    return Int(val + b.val, dx + b.dx);
}

Int Int::operator +(const int&b) const {
    return Int(val + b, dx);
}

Int operator +(const int&a, const Int&b) {
    return b + a;
}

Int Int::operator -(const Int&b) const {
    return Int(val - b.val, dx - b.dx);
}

Int Int::operator -(const int&b) const {
    return Int(val - b, dx);
}

Int operator -(const int&a, const Int&b) {
    return Int(a - b.val, -b.dx); // sub does not commute
}

Int Int::operator /(const Int&b) const {
    return Int(val / b.val, (dx * b.val - val * b.dx) / b.val / b.val);
}

Int Int::operator /(const int&b) const {
    return Int(val / b, dx / b);
}

Int operator /(const int&a, const Int&b) {
    return Int(a / b.val, - a * b.dx / b.val / b.val); // divide does not commute
}
