//
//  GumowskiMira.hpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/11.
//
//

#ifndef GumowskiMira_hpp
#define GumowskiMira_hpp

#include <stdio.h>
#include <ofMain.h>

class GumowskiMira{
private:
    double a, b;
    float u;
    double addingA, addingB, addingU;
    int size;
    
    int numPoint = 1500;
    
    class pointData{
    public:
        double x, y, Gx;
        pointData(double _x, double _y, double _Gx){
            x = _x;
            y = _y;
            Gx = _Gx;
        }
    };
    
    vector<pointData> data;
    
    int height, width;
    
public:
    
    GumowskiMira(int _numPoint, int _width, int _height);
    void calcGraph();
    void drawGraph();
    
    //setter
    
    void setU(float _u);
    void setSize(int _size);
    void setNumOfPoint(int _numOfPoint);
    
    
};
#endif /* GumowskiMira_hpp */
