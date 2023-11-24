#include <iostream>
#include <fstream>
#include "string"

struct Figure {
    std::string stroke;
    double stroke_width;

};


struct Line: Figure {
    double x1;
    double y1;
    double x2;
    double y2;
  //  std::string stroke;
  //  double stroke_width;
    Line(double x_1, double y_1, double x_2, double y_2, std::string _stroke, double _stroke_width) {
        x1 = x_1;
        y1 = y_1;
        y2 = y_2;
        x2 = x_2;
        stroke = _stroke;
        stroke_width = _stroke_width;
    }

};
    std::ostream& operator<<(std::ostream& os, const Line& l) {
        return os << "<line x1=\"" << l.x1 << "\" y1=\"" << l.y1 << "\" x2=\"" << l.x2 << "\" y2=\"" << l.y2 << "\" stroke=\"" << l.stroke << "\" stroke-width=\"" << l.stroke_width << "\" />";
    }

struct Circle: Figure {
    double cx;
    double cy;
    double r;
    double opacity;
    std::string fill;
   // double stroke_width;
    Circle(double _cx, double _cy, double _r, std::string _fill,std::string _stroke, double _stroke_width) {
        cx = _cx;
        cy = _cy;
        r = _r;
        
        fill = _fill;
        stroke = _stroke;
        stroke_width = _stroke_width;
    }
};

    std::ostream& operator<<(std::ostream& os, const Circle& c) {
        return os << "<circle cx=\"" << c.cx << "\" cy=\"" << c.cy << "\" r=\"" << c.r  << "\" fill=\"" << c.fill << "\" stroke=\"" << c.stroke << "\" stroke-width=\"" << c.stroke_width << "\" />";
    }

struct Poligon : Figure {
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    std::string fill;
    Poligon(double x_1, double y_1, double x_2, double y_2, double x_3, double y_3, double x_4, double y_4, std::string _fill, std::string _stroke) {
        x1 = x_1;
        y1 = y_1;
        x2 = x_2;
        y2 = y_2;
        x3 = x_3;
        y3 = y_3;
        x4 = x_4;
        y4 = y_4;
        fill = _fill;
        stroke = _stroke;
    }
};
     std::ostream& operator<<(std::ostream& os, const Poligon& p) {
        return os << "<polygon points=\"" << p.x1 << "," << p.y1 << " " << p.x2 << "," << p.y2 << " " << p.x3 << "," << p.y3 << " " << p.x4 << "," << p.y4 << "\" fill=\"" << p.fill << "\" stroke=\"" << p.stroke << "\" />";
    }







int main() {
    std::ofstream svg("img.svg");
    Line line(200, 200, 700, 300, "black", 3);

    Circle circle(400, 400, 350,  "none","black",25);
    
    Circle circle1(565, 195, 40, "purple", "black", 1);
    Poligon pol1(100, 0, 250, 0, 800, 450, 800, 750, "#75998D","black");

    Poligon pol2(0, 600, 0, 800, 800, 0,750, 0, "#C5AE7C","black");
   
    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"800\"  style=\"background-color: #DAD0BF;\">";
    svg << pol1  << pol2  << circle <<circle1<< line;
    svg << "</svg>";
    svg.close();
    return 0;
}
