#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int getRopeLength(int fieldDiameter, double eatenRatio) {
    if (fieldDiameter <= 0 || eatenRatio <= 0.0) return 0;
    if (eatenRatio >= 1.0) return fieldDiameter;

    long double R = fieldDiameter / 2.0L;
    long double PI = acos(-1.0L);
    long double targetArea = (PI * R * R) * (long double)eatenRatio;

    long double low = 0.0L;
    long double high = (long double)fieldDiameter;
    
    for (int i = 0; i < 100; i++) {
        long double L = (low + high) / 2.0L;

        long double cos_alfa = L / (2.0L * R);
        if (cos_alfa > 1.0L) cos_alfa = 1.0L;
        if (cos_alfa < -1.0L) cos_alfa = -1.0L;
        long double alfa = acos(cos_alfa);

        long double cos_beta = 1.0L - (L * L) / (2.0L * R * R);
        if (cos_beta > 1.0L) cos_beta = 1.0L;
        if (cos_beta < -1.0L) cos_beta = -1.0L;
        long double beta = acos(cos_beta);

        long double area = L * L * alfa - L * L * sin(alfa) * cos_alfa + 
                           R * R * beta - R * R * sin(beta);

        if (area < targetArea) {
            low = L;
        } else {
            high = L;
        }
    }


    return (int)(low + 1e-10);
}