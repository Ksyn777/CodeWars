#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getRopeLength(int fieldDiameter, double eatenRatio) {
    if (eatenRatio <= 0) return 0;
    if (eatenRatio >= 1) return fieldDiameter;

    double PI = acos(-1.0);
    double R = fieldDiameter / 2.0;
    double targetArea = (PI * R * R) * eatenRatio;

    double low = 0;
    double high = (double)fieldDiameter;
    double L = 0;

    for (int i = 0; i < 100; i++) {
        L = (low + high) / 2.0;

        double cos_alfa = L / (2.0 * R);
        
        if (cos_alfa > 1.0) cos_alfa = 1.0;
        if (cos_alfa < -1.0) cos_alfa = -1.0;

        double alfa = acos(cos_alfa);
        double beta = asin(L * sin(alfa) / R);

        double poleSprawdzone = L * L * (alfa - sin(alfa) * cos(alfa)) + 
                                R * R * (beta - sin(beta) * cos(beta));

        if (poleSprawdzone < targetArea) {
            low = L;
        } else {
            high = L;
        }
    }
    return (int)(low + 1e-9);
}
