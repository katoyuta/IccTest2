#pragma once
#include "ofMain.h"

class Bacteria{
    
public:
    
    Bacteria();
    
    void update();
    void draw(int x, int y);
    
    bool dead;
    
private:
    
    int frame = 0;
    int volume = 12;
    
    float scale = 1;
    
    int type;
    
    vector<ofPoint> bacteriaPos;
    vector<ofPoint> bacteriaSpeed;
    vector<int> bacteriaType;
    
    ofImage bacteria[5];
    
};