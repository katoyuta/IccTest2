
#include "Bacteria.h"


Bacteria::Bacteria(){
    
    frame = 0;
    
    scale = ofGetWidth()/100.f;
    
    
    bacteria[0].loadImage("img/bacteria1.png");
    bacteria[1].loadImage("img/bacteria2.png");
    bacteria[2].loadImage("img/bacteria3.png");
    bacteria[3].loadImage("img/bacteria4.png");
    bacteria[4].loadImage("img/bacteria5.png");
    
    for (int i = 0; i < volume; i++) {
        
        float r = ofRandom(20) * scale;
        float angle = ofRandom(PI*2) * scale;
        
        float s = ofRandom(10);
        float angle2 = ofRandom(PI*2) * scale;
        
        bacteriaPos.push_back( ofPoint( cos(angle)*r, sin(angle)*r) );
        bacteriaSpeed.push_back( ofPoint( cos(angle2)*s, sin(angle2)*s) );
        bacteriaType.push_back( ofRandom(4) );
    }
    
};


void Bacteria::update(){
    
    for (int i = 0; i < bacteriaPos.size(); i++) {
        
        //bacteriaSpeed[i] -=  5000 * bacteriaPos[i].getNormalized() / bacteriaPos[i].lengthSquared();
        bacteriaSpeed[i] *= 0.8;
        
        float s = ofRandom(6);
        float angle2 = ofRandom(PI*2) * scale;
        
        bacteriaSpeed[i] += ofPoint( cos(angle2)*s, sin(angle2)*s);
        
        bacteriaPos[i] += bacteriaSpeed[i];
        
        if(bacteriaPos[i].length() > 80){
          bacteriaSpeed[i] +=  -bacteriaPos[i].getNormalized() * 0.005 * (bacteriaPos[i].length() - 30);
        }
    }
    
}

void Bacteria::draw(int x, int y){
    
    ofSetColor(255);
   
    ofEnableAlphaBlending();
    
    glDisable(GL_DEPTH_TEST);
    
    for (int i = 0; i < bacteriaPos.size(); i++) {
        ofPoint pos;
        pos.set(bacteriaPos[i].x + x, bacteriaPos[i].y + y);
        
        //ofCircle(bacteriaPos[i].x + x, bacteriaPos[i].y + y, 2 * scale);
        
        float w = bacteria[bacteriaType[i]].width * scale / 20.f;
        float h = bacteria[bacteriaType[i]].height * scale / 20.f;
        
        
        bacteria[bacteriaType[i]].draw(pos.x - w/2, pos.y -h/2, w, h);
        
    }
    
    glEnable(GL_DEPTH_TEST);
    
    ofDisableAlphaBlending();
}