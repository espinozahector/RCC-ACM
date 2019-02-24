// http://socalcontest.org/history/2009/socal2009.pdf
// Problem 2: Serpentine Belt

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Pulley {
    float x, y, r;
    bool inside;
};

float dist(int x1, int y1, int x2, int y2) {
    return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float lOpen(Pulley p1, Pulley p2) {
    float C = dist(p1.x, p1.y, p2.x, p2.y);

    float R1 = (p1.r > p2.r) ? p1.r : p2.r;
    float R2 = (p1.r > p2.r) ? p2.r : p1.r;

    return sqrt( C * C - (R1 - R2) * (R1 - R2) );
}

float lCross(Pulley p1, Pulley p2) {
    float C = dist(p1.x, p1.y, p2.x, p2.y);

    float R1 = (p1.r > p2.r) ? p1.r : p2.r;
    float R2 = (p1.r > p2.r) ? p2.r : p1.r;

    return sqrt( C * C - (R1 + R2) * (R1 + R2) );
}

float aOpen(Pulley p1, Pulley p2) {
    float C = dist(p1.x, p1.y, p2.x, p2.y);

    float R1 = (p1.r > p2.r) ? p1.r : p2.r;
    float R2 = (p1.r > p2.r) ? p2.r : p1.r;

    return asin((R1 - R2) / C);
}

float aCross(Pulley p1, Pulley p2) {
    float C = dist(p1.x, p1.y, p2.x, p2.y);

    float R1 = (p1.r > p2.r) ? p1.r : p2.r;
    float R2 = (p1.r > p2.r) ? p2.r : p1.r;

    return asin((R1 + R2) / C);
}

int main() {

    vector<Pulley> points;

    // Input
    while (!cin.eof()) {
        Pulley p;
        cin >> p.x >> p.y;

        float temp;
        cin >> temp;
        if (temp > 0) {
            p.r = temp;
            p.inside = true;
        } else {
            p.r = -temp;
            p.inside = false;
        }

        points.push_back(p);
    }

    float l = 0; // Length of the belt

    // Get the length of the belt between each pulley
    for (int i = 0; i < points.size(); i++) {
        Pulley p1 = points[i];
        Pulley p2;
        if (i + 1 < points.size()) p2 = points[i + 1];
        else p2 = points[0];

        if (p2.inside == p1.inside) {
            // Open
            l += lOpen(p1, p2);
        } else {
            // Cross
            l += lCross(p1, p2);
        }
    }

    // Get the length of the belt wrapped around each pulley

    for (int i = 0; i < points.size(); i++) {
        Pulley p1 = points[i]; // Pulley with belt wrapped

        Pulley p2; // Adjacent pulley
        if (i + 1 < points.size()) p2 = points[i + 1];
        else p2 = points[0];

        Pulley p0; // Adjacent pulley
        if (i - 1 >= 0) p0 = points[i - 1];
        else p0 = points[points.size() - 1];

        // Get the angle between the adjacent pulleys
        float D1 = dist(p0.x, p0.y, p1.x, p1.y);
        float D2 = dist(p2.x, p2.y, p1.x, p1.y);

        float x1 = (p0.x - p1.x);
        float y1 = (p0.y - p1.y);
        
        float x2 = (p2.x - p1.x);
        float y2 = (p2.y - p1.y);

        float theta = M_PI - acos( ( x1 * x2 + y1 * y2 ) / (D1 * D2) );

        float phi1, phi2;

        // Phi1 (between p0 and p1)
        if (p0.inside == p1.inside) {
            // Open
            if (p0.r < p1.r) phi1 = aOpen(p1, p0);
            else phi1 = -aOpen(p1, p0);
        } else {
            // Cross
            phi1 = aCross(p1, p0);
        }

        // Phi2 (between p2 and p1)
        if (p2.inside == p1.inside) {
            // Open
            if (p2.r < p1.r) phi2 = aOpen(p1, p2);
            else phi2 = -aOpen(p1, p2);
        } else {
            // Cross
            phi2 = aCross(p1, p2);
        }

        // Add the arc length, S = R * Theta
        l += p1.r * (phi1 + phi2 + theta);
    }

    // Output the answer rounded
    cout << static_cast<int>(l + 0.5f) << endl;

    return 0;
}