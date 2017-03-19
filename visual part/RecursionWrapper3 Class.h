#include "ofApp.h"

class RecursionWrapper3{
private:
    float circleWidth;
    float circleHeight;
    float circleRadius;
    
    ofPlanePrimitive plane;
    
    
    
public:
    static ofTexture text;
    
    RecursionWrapper3(float width, float height, float radius) : circleWidth(width*16/9),circleHeight(height),circleRadius(radius) {
        
    };
    
    
    void setup(){
        
        
        
        
        
    }
    
    void draw(){
        int randomm = ofRandom(192);
        int Xin = ofClamp(ofMap(((ofApp*)ofGetAppPtr())->icoPos2.x, 0, 2304, 0, 48), 0, 48);
        
      
        plane.set(circleWidth, ((ofApp*)ofGetAppPtr())->mouseZ + 100 + ofClamp(((ofApp*)ofGetAppPtr())->icoPos2.y /100, 0, 50));
    
        
        if(randomm > Xin){
            plane.mapTexCoords(0, text.getHeight()/ofRandom(6), text.getWidth()/ofRandom(6), 0);
        }else{
            plane.mapTexCoords(0, ((ofApp*)ofGetAppPtr())->black.getHeight(), ((ofApp*)ofGetAppPtr())->black.getWidth(), 0);
        }
        
        
        
        if(ofGetElapsedTimef() > 107 && ofGetElapsedTimef() < 228.70){
            
            vector<ofPoint> &vertices = plane.getMesh().getVertices();
            
            ofPoint v2 = vertices[0];
            
            for(int i = 0; i<vertices.size(); i++){
                ofPoint v;
            
                v.x = v2.x;
                v.y = v2.y;
    
                
                v2.x = fmod((1.50 * v.x + 0.02), 1);
                v2.y = fmod((1.50 * v.y + 0.02), 1);
                
                vertices[i].x = v.x * circleWidth/2;
                vertices[i].y = v.y * circleHeight/2;
          
            }

            
        }
        
        
        if(ofGetElapsedTimef() > 228.70){
            vector<ofPoint> &vertices = plane.getMesh().getVertices();
            
            ofPoint v2 = vertices[0];
            
            for(int i = 0; i<vertices.size(); i++){
                ofPoint v;
                
                v.x = v2.x;
                v.y = v2.y;
                v.z = v2.z;
                
                v2.x = fmod((1.56 * v.x + 0.02), 1);
                v2.y = fmod((1.34 * v.y + 0.02), 1);
                v2.z = fmod((1.03 * v.z + 0.02), 1);
                
                vertices[i].x = v.x * circleWidth/2;
                vertices[i].y = v.y * circleHeight/2;
                vertices[i].z = v.z * circleHeight/2;
            }

        }
        
        
        
        
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 , ofGetHeight()/2);
        
        if(randomm > Xin){
            text.bind();
        }else{
            ofPushStyle();
            ofSetColor(255,255,255,245);
            ((ofApp*)ofGetAppPtr())->black.bind();
        }
        
        plane.draw();
        
        if(randomm >Xin){
            text.unbind();
        }else{
            ((ofApp*)ofGetAppPtr())->black.unbind();
            ofPopStyle();
        }
        
        
        ofPopMatrix();
        
        
    }
    
    
    
    
};
