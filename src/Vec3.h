#ifndef VEC3_H
#define VEC3_H

template<typename _Tp>
class Vec3 {
public:
    Vec3(_Tp _x = 0, _Tp _y = 0, _Tp _z = 0) : x(_x), y(_y), z(_z) {}

    template<typename _Tp2>
    Vec3(const Vec3<_Tp2> &v) : x(v.x), y(v.y), z(v.z) {}

    template<typename _Tp2>
    Vec3 & operator = (const Vec3<_Tp2> &rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
        }
        return *this;
    }

    bool operator < (const Vec3<_Tp> &that) const {
        return (x < that.x) || (x == that.x && y < that.y) || (x == that.x && y == that.y && z < that.z);
    }

    bool operator == (const Vec3<_Tp> &that) const {
        return (x == that.x && y == that.y && z == that.z);
    }

    Vec3 unit() const {
        _Tp len = length();
        if (len < 1e-8) return Vec3<_Tp>();
        double invlen = 1./len;
        return Vec3(x*invlen, y*invlen, z*invlen);
    }

    _Tp length() const {
        return _Tp(sqrt(x*x + y*y + z*z));
    }

    _Tp dot(const Vec3<_Tp> &v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    Vec3 add(const Vec3<_Tp> &v) const {
        return Vec3<_Tp>(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator + (const Vec3<_Tp>  &v) const {
        return Vec3<_Tp>(x + v.x, y + v.y, z + v.z);
    }
    Vec3 add(const _Tp f) const {
        return Vec3<_Tp>(x + f, y + f, z + f);
    }
    Vec3 operator + (const _Tp f) const {
        return Vec3<_Tp>(x + f, y + f, z + f);
    }

    Vec3 subtract(const Vec3<_Tp> &v) const {
        return Vec3<_Tp>(x - v.x,  y - v.y, z - v.z);
    }
    Vec3 operator - (const Vec3<_Tp> &v) const {
        return Vec3<_Tp>(x - v.x,  y - v.y, z - v.z);
    }
    Vec3 subtract(const _Tp f) const {
        return Vec3<_Tp>(x - f, y - f, z - f);
    }
    Vec3 operator - (const _Tp f) const {
        return Vec3<_Tp>(x - f, y - f, z - f);
    }

    Vec3 multiply(const _Tp f) const {
        return Vec3<_Tp>(x*f, y*f, z*f);
    }
    Vec3 operator * (const _Tp f) const {
        return Vec3<_Tp>(x*f, y*f, z*f);
    }

    Vec3 divide(const _Tp f) const {
        _Tp inv_f = _Tp(1)/f;
        return Vec3<_Tp>(x*inv_f, y*inv_f, z*inv_f);
    }
    Vec3 operator / (const _Tp f) const {
        _Tp inv_f = _Tp(1)/f;
        return Vec3<_Tp>(x*inv_f, y*inv_f, z*inv_f);
    }


    Vec3 cross(const Vec3<_Tp> &v) const {
        return Vec3<_Tp>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
    }

    template<typename _Tp2>
    void toArray(_Tp2 a[3]) const {
        a[0] = x;
        a[1] = y;
        a[2] = z;
    }

    static Vec3<_Tp> lerp(const Vec3<_Tp> &a, const Vec3<_Tp> &b, float fraction) {
        _Tp x = a.x + (b.x - a.x) * t;
        _Tp y = a.y + (b.y - a.y) * t;
        _Tp z = a.z + (b.z - a.z) * t;
        return Vec3<_Tp>(x, y, z);
    }

    static Vec3 fromAngles(_Tp theta, _Tp phi) {
        return Vec3<_Tp>(cos(theta) * cos(phi), sin(phi), sin(theta) * cos(phi));
    }

public:
    _Tp x, y, z;
};

template<typename _Tp>
Vec3<_Tp> operator * (const _Tp f, const Vec3<_Tp> &v) {
    return Vec3<_Tp>(f*v.x, f*v.y, f*v.z);
}

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;
typedef Vec3<int> Vec3i;

#endif // VEC3_H
