class Int {
private:
    long long val;
    double dx;
public:
    Int (long long);
    Int (long long, long long);
    long long get_dx(int) const;
    operator int();
    Int& operator=(const int&);
    Int operator *(const Int&) const;
    Int operator *(const int&) const;
    friend Int operator *(const int&, const Int&);
    Int operator +(const Int&) const;
    Int operator +(const int&) const;
    friend Int operator +(const int&, const Int&);
    Int operator -(const Int&) const;
    Int operator -(const int&) const;
    friend Int operator -(const int&, const Int&);
    Int operator /(const Int&) const;
    Int operator /(const int&) const;
    friend Int operator /(const int&, const Int&);
};
