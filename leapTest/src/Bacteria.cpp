
#include "Bacteria.h"


Bacteria::Bacteria(){
    
    frame = 0;
    volume = 40;
    
    alpha = 0;
    
    scale = ofGetWidth()/100.f;

    dead = false;
    
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
        bacteriaType.push_back( ofRandom(5) );
        bacteriaRotation.push_back( ofRandom(360) );
    }
    
};

void Bacteria::reset(){
    
    frame = 0;
    dead = false;
    
    bacteriaPos.clear();
    bacteriaSpeed.clear();
    bacteriaType.clear();
    bacteriaRotation.clear();
    
    for (int i = 0; i < volume; i++) {
        
        float r = ofRandom(20) * scale;
        float angle = ofRandom(PI*2) * scale;
        
        float s = ofRandom(10);
        float angle2 = ofRandom(PI*2) * scale;
        
        bacteriaPos.push_back( ofPoint( cos(angle)*r, sin(angle)*r) );
        bacteriaSpeed.push_back( ofPoint( cos(angle2)*s, sin(angle2)*s) );
        bacteriaType.push_back( ofRandom(5) );
        bacteriaRotation.push_back( ofRandom(360) );
    }
    
}


void Bacteria::setElimination(int n){
    //除菌する
    
    for (int i = 0; i < n; i++) {
        
        std::vector<ofPoint>::iterator it = bacteriaPos.erase(bacteriaPos.end()-1);
        
    }
}


void Bacteria::update(bool visible){
    
    if (visible) {
        alpha += ( 1 - alpha ) * 0.1f;
    }else{
        alpha += ( 0 - alpha ) * 0.1f;
    }
    
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
    
    
    frame ++;
    
    if (!dead && frame%45 ==0) {
        
        setElimination(1);
        
        if(bacteriaPos.size() == 0){
            dead = true;
        }
    }
    
}

void Bacteria::draw(int x, int y){
    
    ofSetColor(255,255,255,200 * alpha);
   
    ofEnableAlphaBlending();
    
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    
    glDisable(GL_DEPTH_TEST);
    
    for (int i = 0; i < bacteriaPos.size(); i++) {
        ofPoint pos;
        pos.set(bacteriaPos[i].x + x, bacteriaPos[i].y + y);
        
        //ofCircle(bacteriaPos[i].x + x, bacteriaPos[i].y + y, 2 * scale);
        
        float w = bacteria[bacteriaType[i]].width * scale / 30.f;
        float h = bacteria[bacteriaType[i]].height * scale / 30.f;
        
        ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotate(bacteriaRotation[i]);
        
        //bacteria[bacteriaType[i]].draw(pos.x - w/2, pos.y -h/2, w, h);
        bacteria[bacteriaType[i]].draw( -w/2, -h/2, w, h);
        
        ofPopMatrix();
    }
    
    glEnable(GL_DEPTH_TEST);
    
    ofDisableBlendMode();
    
    ofDisableAlphaBlending();
}