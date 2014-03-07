#pragma once
#include "ofMain.h"

class Bacteria{
    
public:
    
    Bacteria();
    
    void update();
    void draw(int x, int y);
    
    void reset();
    void setElimination(int n);
    
    bool dead;
    
private:
    
    int frame;
    int volume;
    
    float scale;
    
    int type;
    
    vector<ofPoint> bacteriaPos;
    vector<ofPoint> bacteriaSpeed;
    vector<int> bacteriaType;
    
    
    
    ofImage bacteria[5];
    
};