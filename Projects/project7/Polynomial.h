#include<iostream>
using namespace std;

class Polynomial {
public:
	Polynomial();
	Polynomial(int, int *);
	Polynomial(const Polynomial &);
	~Polynomial();
	int solve(int);
	Polynomial & operator=(const Polynomial &);
	bool operator==(const Polynomial &) const;
	bool operator!=(const Polynomial &) const;
	friend Polynomial operator*(const Polynomial &, const Polynomial &);
	friend Polynomial operator*(const Polynomial &, int);
	friend ostream& operator<<(ostream &, const Polynomial &);
	friend istream& operator>>(istream &, Polynomial &);
	friend Polynomial operator+(const Polynomial &, const Polynomial &);
	friend Polynomial operator-(const Polynomial &, const Polynomial &);
private:
	int * coefficients;
	int degree;
};
