#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double Dis(const Point& p, const Point& q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double Forceclosepair(const std::vector<Point>& P) {
    double minDis = std::numeric_limits<double>::max();
    for (size_t i = 0; i < P.size(); ++i) {
        for (size_t j = i + 1; j < P.size(); ++j) {
            minDis = std::min(minDis, Dis(P[i], P[j]));
        }
    }
    return minDis;
}

double sClosest(const std::vector<Point>& s, double d) {
    double minDis = d;

    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j < s.size() && (s[j].y - s[i].y) < minDis; ++j) {
            minDis = std::min(minDis, Dis(s[i], s[j]));
        }
    }
    return minDis;
}

double Utilclosepair(const std::vector<Point>& P) {
    if (P.size() <= 3) {
        return Forceclosepair(P);
    }

    size_t mid = P.size() / 2;
    Point midPoint = P[mid];

    std::vector<Point> leftHalf(P.begin(), P.begin() + mid);
    std::vector<Point> rightHalf(P.begin() + mid, P.end());

    double dist1 = Utilclosepair(leftHalf);
    double dist2 = Utilclosepair(rightHalf);
    double d = std::min(dist1, dist2);

    std::vector<Point> s;
    for (const Point& p : P) {
        if (std::abs(p.x - midPoint.x) < d) {
            s.push_back(p);
        }
    }

    std::sort(s.begin(), s.end(), compY);

    return std::min(d, sClosest(s, d));
}

double closestPair(const std::vector<Point>& P) {
    std::vector<Point> sX = P;
    std::sort(sX.begin(), sX.end(), compX);
    return Utilclosepair(sX);
}

int main() {
    std::vector<Point> P = {{1, 4}, {15, 30}, {50, 70}, {1, 5}, {12, 10}, {7, 2}};
    std::cout << "Closest pair distance: " << closestPair(P) << std::endl;
    return 0;
}
