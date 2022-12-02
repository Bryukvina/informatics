#include <iostream>
#include <cmath>
#include <vector>
#define _USE_MATH_DEFINES

struct Point{
    double x;
    double y;
};

class figure{
    public:
        int count_v;
        Point **vertexes;

        figure();
        ~figure() = default;

        virtual double square();

        virtual double perimetr();

        virtual void take_inf();
};


class elipse: public figure{
    public:
        Point center1;
        Point center2;

        double a; //большая полуось
        double b; // малая полуось

        elipse(){center1.x = 0; center1.y = 0; center2.x = 0; center2.y = 0; a = 0 ; b = 0;};
        elipse(Point p1, Point p2, double a_, double b_){center1 = p1; center2 = p2;a = a_; b = b_;};
        ~elipse() = default;

        double square(){
            double S;
            S = M_PI * a * b;
            return S;
        };

        double perimetr(){
            double P;
            P = 4 * ((M_PI * a * b + a - b)/(a + b));
            return P;
        };

        void take_inf(){
            std::cout << "Center1: x = " << center1.x << "; y = "<< center1.y << std::endl;
            std::cout << "Center2: x = " << center2.x << "; y = "<< center2.y << std::endl;
            std::cout << "semi-major axis = " << a << std::endl;
            std::cout << "semi-minor axis = " << b << std::endl;
        };

};

class circul: public figure{
    public:
        Point center;
        double R;

        circul(){center.x = 0; center.y = 0; R = 0;};
        circul(Point p1, double R_){center = p1; R = R_;};
        ~circul() = default;

        double square(){
            double S;
            S = M_PI * R * R;
            return S;
        };

        double perimetr(){
            double P;
            P = 2 * M_PI * R;
            return P;
        };

        void take_inf(){
            std::cout << "Center: x = " << center.x << "; y = "<< center.y << std::endl;
            std::cout << "Radius = " << R << std::endl;
        };
};

class rectangle: public figure{
    public:
        std::vector<Point> vertexes[4];

        rectangle(){std::vector<Point> vertexes[4];};
        rectangle(std::vector<Point> array){
            int i;
            for (i = 0; i < 5; i++){
                Point c = array[i];
                vertexes[i].x = c.x;
                vertexes[i].y = c.y;
            };
        };
        ~rectangle() = default;

        double square(){
            double S;
            S = ((vertexes[0].x - vertexes[1].x) ^ 2 + (vertexes[0].y - vertexes[1].y) ^ 2) ^ 0.5 * (vertexes[1].x - vertexes[2].x) ^ 2 + (vertexes[1].y - vertexes[2].y) ^ 2) ^ 0.5;
            return S;
        };

        double perimetr(){
            int i;
            double P;
            double dx;  
            double dy;

            for (i = 0; i < 4; i++){
                dx = vertexes[i + 1].x - vertexes[i].x;
                dy = vertexes[i + 1].y - vertexes[i].y;
                P += ((dx * dx) + (dy * dy)) ^ 0.5;
            };
            return P;
        };

        void take_inf(){
            int i;

            std::cout << "The number of the vertexes: " << count_v << std::endl;
            std::cout << "List of the vertexes: ";
            for (i = 0; i < count_v; i++){
                std::cout << "x = " << vertexes[i].x << "; y = " << vertexes[i].y << std::endl;
            };
        };
};


class quadrate: public figure{
    public:
        std::vector<Point> vertexes[4];

        quadrate(){std::vector<Point> vertexes[4];};
        quadrate(std::vector<Point> array){
            int i;
            for (i = 0; i < 4; i++){
                Point c = array[i];
                vertexes[i].x = c.x;
                vertexes[i].y = c.y;
            };
        };
        ~quadrate() = default;

        double square(){
            double S;
            S = (vertexes[0].x - vertexes[1].x) ^ 2 + (vertexes[0].y - vertexes[1].y) ^ 2;
            return S;
        };

        double perimetr(){
            int i;
            double P;
            double dx;
            double dy;

            for (i = 0; i < 4; i++){
                dx = vertexes[i + 1].x - vertexes[i].x;
                dy = vertexes[i + 1].y - vertexes[i].y;
                P += ((dx * dx) + (dy * dy)) ^ 0.5;
            };
            return P;
        };

        void take_inf(){
            int i;

            std::cout << "The number of the vertexes: " << count_v << std::endl;
            std::cout << "List of the vertexes: ";
            for (i = 0; i < count_v; i++){
                std::cout << "x = " << vertexes[i].x << "; y = " << vertexes[i].y << std::endl;
            };
        };

};

class triangle: public figure{
    public:
        std::vector<Point> vertexes[4];

        triangle(){std::vector<Point> vertexes[4];};
        triangle(std::vector<Point> array){
            int i;
            for (i = 0; i < 4; i++){
                Point c = array[i];
                vertexes[i].x = c.x;
                vertexes[i].y = c.y;
            };
        };
        ~triangle() = default;

        double square(){
            double S;
            double a;
            double b;
            double c;
            double p;

            a = ((vertexes[0].x - vertexes[1].x) ^ 2 + (vertexes[0].y - vertexes[1].y) ^ 2) ^ 0.5;
            b = ((vertexes[1].x - vertexes[2].x) ^ 2 + (vertexes[1].y - vertexes[2].y) ^ 2) ^ 0.5;
            c = ((vertexes[2].x - vertexes[0].x) ^ 2 + (vertexes[2].y - vertexes[0].y) ^ 2) ^ 0.5;

            p = (a + b + c) / 2;
            S = (p * (p - a) * (p - b) * (p - c)) ^ 0.5;
            return S;
        };

        double perimetr(){
            double a;
            double b;
            double c;
            double P;

            a = ((vertexes[0].x - vertexes[1].x) ^ 2 + (vertexes[0].y - vertexes[1].y) ^ 2) ^ 0.5;
            b = ((vertexes[1].x - vertexes[2].x) ^ 2 + (vertexes[1].y - vertexes[2].y) ^ 2) ^ 0.5;
            c = ((vertexes[2].x - vertexes[0].x) ^ 2 + (vertexes[2].y - vertexes[0].y) ^ 2) ^ 0.5;

            P = a + b + c;
            return P;
        };

        void take_inf(){
            int i;

            std::cout << "The number of the vertexes: " << count_v << std::endl;
            std::cout << "List of the vertexes: ";
            for (i = 0; i < count_v; i++){
                std::cout << "x = " << vertexes[i].x << "; y = " << vertexes[i].y << std::endl;
            };
        };

};
