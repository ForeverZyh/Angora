class Int {
private:
    int val;
    int dx;
public:
    Int (int);
    Int (int, int);
    int get_dx(int) const;
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
};
