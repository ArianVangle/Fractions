#ifndef FRACTIONS_HPP
#define FRACTIONS_HPP
#include <cmath>


class Fractions {
    public:
        Fractions() : x(0), y(0) {}
        Fractions(const int a, const int b) {
            int g = gcd(a, b);
            this->x = a / g;
            this->y = b / g;
        }
        // сложение
        const Fractions operator+(const Fractions &rv) const {
            int l = lcm(rv.y, y);
            int a = x*l/y + rv.x * l/rv.y;
            return Fractions(a, l);
        }
        const Fractions operator+(const int rv) const {
            int l = lcm(rv, y);
            int a = x*l/y + rv * l;
            return Fractions(a, l);
        }
        const double operator+(const double rv) const {
            return rv + this->to_float();
        }
        friend Fractions operator+(const int lv, const Fractions &rv) {
            int x = lv;
            int y = 1;
            int l = lcm(y, rv.y);
            int a = x*l/y + rv.x * l/rv.y;
            return Fractions(a, l);
        }
        friend double operator+(double lv, const Fractions &rv) {
            return lv + rv.to_float();
        }

        //вычитание
        const Fractions operator-(const Fractions &rv) const {
            int l = lcm(rv.y, y);
            int a = x*l/y - rv.x * l/rv.y;
            return Fractions(a, l);
        }
        const Fractions operator-(const int rv) const {
            int l = lcm(rv, y);
            int a = x*l/y - rv * l;
            return Fractions(a, l);
        }
        const double operator-(const double rv) const {
            return this->to_float() - rv;
        }
        friend Fractions operator-(const int lv, const Fractions &rv) {
            int x = lv;
            int y = 1;
            int l = lcm(y, rv.y);
            int a = x*l/y - rv.x * l/rv.y;
            return Fractions(a, l);
        }
        friend double operator-(double lv, const Fractions &rv) {
            return lv - rv.to_float();
        }

        // умножение
        const Fractions operator*(const Fractions &rv) const {
            int a = x*rv.x;
            int b = y*rv.y;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        const Fractions operator*(const int rv) const {
            int a = x*rv;
            int b = y*1;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        const double operator*(const double rv) const {
            return this->to_float() * rv;
        }
        friend Fractions operator*(const int lv, const Fractions &rv)  {
            int a = lv*rv.x;
            int b = rv.y*1;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        friend double operator*(const double lv, const Fractions &rv)  {
            return lv * rv.to_float(); 
        }

        //деление
        const Fractions operator/(const Fractions &rv) const {
            int a = x*rv.y;
            int b = y*rv.x;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        const Fractions operator/(const int rv) const {
            int a = x*rv;
            int b = y;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        const double operator/(const double rv) const {
            return this->to_float() / rv;
        }
        friend Fractions operator/(const int lv, const Fractions &rv) {
            int a = lv*rv.y;
            int b = rv.x;
            int g = gcd(a, b);
            return Fractions(a/g, b/g);
        }
        friend double operator/(const double lv, const Fractions &rv) {
            return lv / rv.to_float();
        }
        
        // Сравнение Fractions с Fractions
        const int operator==(const Fractions &rv) const {
            return (x == rv.x && y == rv.y);
        }
        const bool operator!=(const Fractions &rv) const {
            return !(x == rv.x && y == rv.y);
        }
        const bool operator>(const Fractions &rv) const {
            return this->to_float() > rv.to_float();
        }
        const int operator<(const Fractions &rv) const {
            return this->to_float() < rv.to_float();
        }
        const bool operator>=(const Fractions &rv) const {
            return !(*this < rv);
        }
        const bool operator<=(const Fractions &rv) const {
            return !(*this > rv);
        }

        // Сравнение Fractions с int 
        const bool operator==(const int rv) const {
            return this->to_float() == static_cast<double>(rv);
        }
        const bool operator!=(const int rv) const {
            return !(*this == rv);
        }
        const bool operator>(const int rv) const {
            return this->to_float() > static_cast<double>(rv);
        }
        const bool operator<(const int rv) const {
            return this->to_float() < static_cast<double>(rv);
        }
        const bool operator>=(const int rv) const {
            return !(*this < rv);
        }
        const bool operator<=(const int rv) const {
            return !(*this > rv);
        }

        // Сравнение int с Fractions 
        friend bool operator==(const int lv, const Fractions &rv) {
            return rv == lv;
        }
        friend bool operator!=(const int lv, const Fractions &rv) {
            return !(lv == rv);
        }
        friend bool operator>(const int lv, const Fractions &rv) {
            return static_cast<double>(lv) > rv.to_float();
        }
        friend bool operator<(const int lv, const Fractions &rv) {
            return static_cast<double>(lv) < rv.to_float();
        }
        friend bool operator>=(const int lv, const Fractions &rv) {
            return !(lv < rv);
        }
        friend bool operator<=(const int lv, const Fractions &rv) {
            return !(lv > rv);
        }

        // Сравнение Fractions с double 
        const bool operator==(const double rv) const {
            return this->to_float() == rv;
        }
        const bool operator!=(const double rv) const {
            return !(*this == rv);
        }
        const bool operator>(const double rv) const {
            return this->to_float() > rv;
        }
        const bool operator<(const double rv) const {
            return this->to_float() < rv;
        }
        const bool operator>=(const double rv) const {
            return !(*this < rv);
        }
        const bool operator<=(const double rv) const {
            return !(*this > rv);
        }

        // Сравнение double с Fractions 
        friend bool operator==(const double lv, const Fractions &rv) {
            return rv == lv;
        }
        friend bool operator!=(const double lv, const Fractions &rv) {
            return !(lv == rv);
        }
        friend bool operator>(const double lv, const Fractions &rv) {
            return lv > rv.to_float();
        }
        friend bool operator<(const double lv, const Fractions &rv) {
            return lv < rv.to_float();
        }
        friend bool operator>=(const double lv, const Fractions &rv) {
            return !(lv < rv);
        }
        friend bool operator<=(const double lv, const Fractions &rv) {
            return !(lv > rv);
        }
        
        const int getX() const {
            return this->x;
        }
        const int getY() const {
            return this->y;
        }
        const int to_int() const {
            return x/y;
        }
        const float to_float() const {
            return (float)x/y;
        }

    private:
        int x, y;
        static const int gcd(int a, int b)  {
            a = a < 0 ? -a : a; 
            b = b < 0 ? -b : b;
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }   
            return a;
        }
        static const int lcm(int a, int b)  {
            if (a == 0 || b == 0) return 0; 
            return (a / gcd(a, b)) * b;  
        } 
};

#endif // FRACTIONS_HPP