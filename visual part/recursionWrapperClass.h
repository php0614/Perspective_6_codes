
#include "ofApp.h"

class RecursionWrapper{
private:
    float circleWidth;
    float circleHeight;
    float circleRadius;

    ofPlanePrimitive plane;


    
public:
    static ofTexture text;
    
    RecursionWrapper(float width, float height, float radius) : circleWidth(width),circleHeight(width*9/16),circleRadius(radius) {

    
    };
    
    
    void setup(){
//        ofEnableAlphaBlending();
//        ofBlendMode(OF_BLENDMODE_ADD);

        

    
    }
    
    void draw(){
        int randomm = ofRandom(192);
        int mouseXin = ofMap(((ofApp*)ofGetAppPtr())->mouseX, 0, 2304, 10, 56);
        
        if(ofGetElapsedTimef() > 0 && ofGetElapsedTimef() < 95){
           plane.set(circleWidth, ofClamp((ofGetElapsedTimef()-5.0)*15, 0.0, 670.0));
        }else if(ofGetElapsedTimef() > 95){
        plane.set(circleWidth, ((ofApp*)ofGetAppPtr())->mouseZ);
        }
        
        if(randomm > mouseXin){
        plane.mapTexCoords(0, text.getHeight()/ofRandom(6), text.getWidth()/ofRandom(6), 0);
    }else{
        plane.mapTexCoords(0, ((ofApp*)ofGetAppPtr())->black.getHeight(), ((ofApp*)ofGetAppPtr())->black.getWidth(), 0);
    }
    
        
 
        
        
        
        if(ofGetElapsedTimef() > 228.70){
        vector<ofPoint> &vertices = plane.getMesh().getVertices();
        
        ofPoint v2 = vertices[0];

            
        for(int i = 0; i<vertices.size(); i++){
            ofPoint v;
          
            v.x = v2.x;
            v.y = v2.y;
            v.z = v2.z;
            
            if(i==0)
            v.normalize();
            
            v2.x = fmod((1.12 * v.x + 0.17), 1);
            v2.y = fmod((1.14 * v.y + 0.13), 1);
            v2.z = fmod((1.09 * v.z + 0.05), 1);
            
        
            
            vertices[i].x = v.x * circleWidth/2;
            vertices[i].y = v.y * circleHeight/2;
            vertices[i].z = v.z * circleHeight/2;
        }
        }
  
//        int rand = ofGetFrameNum()*ofRandom(1,10);
        
//        cam.lookAt(ofVec3f(0, rand, 0));
   
//        cam.setPosition(ofGetWidth()/2, ofGetHeight()/2, 1000);
//        cam.orbit(ofGetWidth()/2, 1080/16+rand, 500);
        
//        cam.begin();
        
        
        
//        int rr = ofRandom(40);
//        if(rr > 1){

        
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 , ofGetHeight()/2);
        
        if(randomm > mouseXin){
        text.bind();
        }else{
            ofPushStyle();
            ofSetColor(255,255,255,245);
            ((ofApp*)ofGetAppPtr())->black.bind();
        }
        
        plane.draw();
        
        if(randomm >mouseXin){
        text.unbind();
        }else{
            ((ofApp*)ofGetAppPtr())->black.unbind();
        ofPopStyle();
        }
        ofPopMatrix();
        
    
        

        
        
//        cam.end();
        
//            ofPushMatrix();
//            ofTranslate(ofGetWidth()/2 , ofGetHeight()/2 );
//            ofPushStyle();
//            ofSetColor(ofColor::red);
//            plane.draw();
//            ofPopStyle();
//            ofPopMatrix();
            
//        }else{
//                    fillTexture.allocate(500, 500, GL_RGBA);
//                    fillFbo.allocate(circleWidth, circleHeight);
//            
//                    for(int i = 0; i<circleWidth*20; i++){
//                        fillMesh.addVertex(ofVec3f(ofRandom(circleWidth), ofRandom(circleHeight), 0));
//                        fillMesh.addIndex(i);
//                        fillMesh.addColor(240);
//                    }
//            
//                    fillFbo.begin();
//                    ofBackground(0);
//                    fillMesh.draw();
//                    fillFbo.end();
//            
//            
//                    ofTexture &fillTexture = fillFbo.getTexture();
//            plane.mapTexCoords(0, fillTexture.getHeight(), fillTexture.getWidth(), 0);
//            
//            ofPushMatrix();
//            ofTranslate(ofGetWidth()/2 , ofGetHeight()/2 );
//            
//            fillTexture.bind();
//            plane.draw();
//            fillTexture.unbind();
//            
//            ofPopMatrix();
//
//            
//            
//        }
    
//        fillFbo.draw(0,0);
//        fillMesh.clear();
//        fillFbo.clear();
        
    }
    
    
    
    
};
