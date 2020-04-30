class Int {
private:
    int val;
    double dx;
public:
    Int (int);
    Int (int, long long);
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
