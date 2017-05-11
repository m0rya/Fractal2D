//
//  Mandelbrot.hpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/12.
//
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>
#include <ofMain.h>

class Mandelbrot{
private:
    ofVec2f center;
    double size;
    float frameWidth;
    
    int NMAX = 200;
    vector<ofColor> colorSet;
    
    
public:
    Mandelbrot(int _width);
    
    int checkDivergence(double a, double b);
    void calcGraph();
    void draw();
    
    
    void zoomIn(ofVec2f point);
};


#endif /* Mandelbrot_hpp */
