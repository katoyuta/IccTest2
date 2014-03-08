#pragma once
#include "ofMain.h"

class Bacteria{
    
public:
    
    Bacteria();
    
    void update(bool visible);
    void draw(int x, int y);
    
    void reset(); //菌の数を初期化
    void setElimination(int n); //菌の数を減らす
    
    bool dead;
    
private:
    
    int frame;
    float scale;
    
    
    int volume; //菌の数
    
    float alpha;
    
    vector<ofPoint> bacteriaPos;
    vector<ofPoint> bacteriaSpeed;
    vector<int> bacteriaType;
    vector<float> bacteriaRotation;
    
    ofImage bacteria[5];
    
};