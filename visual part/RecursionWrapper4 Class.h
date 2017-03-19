//#include "ofApp.h"

class RecursionWrapper4{
private:
    float circleWidth;
    float circleHeight;
    float circleRadius;
    
  
    ofIcoSpherePrimitive sphere;
    
    
    
public:
    static ofTexture text;
    
    RecursionWrapper4(float width, float height, float radius) : circleWidth(width),circleHeight(width*9/16),circleRadius(radius) {
        
   
    };
    
    
    void setup(){
        
        
        
        
        
    }
    
    void draw(){
        int randomm = ofRandom(96);
        int Xin = ofClamp(ofMap(((ofApp*)ofGetAppPtr())->icoPos3.x, 0, 2304, 0, 48), 0, 48);
        
        if(((ofApp*)ofGetAppPtr())->mouseZ>900){
            sphere.set(circleHeight + ((((ofApp*)ofGetAppPtr())->icoPos3.y /220)), 3);

        }else{
            sphere.set(circleHeight + ((((ofApp*)ofGetAppPtr())->icoPos3.y /250)), 3);
        }
        
        if(randomm > Xin){
            sphere.mapTexCoords(0, text.getHeight()/ofRandom(6), text.getWidth()/ofRandom(6), 0);
        }else{
            sphere.mapTexCoords(0, ((ofApp*)ofGetAppPtr())->black.getHeight(), ((ofApp*)ofGetAppPtr())->black.getWidth(), 0);
        }
        
        if(ofGetElapsedTimef() > 228.70){
            vector<ofPoint> &vertices = sphere.getMesh().getVertices();
            
            ofPoint v2 = vertices[0];
            
            for(int i = 0; i<vertices.size()/4; i++){
                ofPoint v;
                
                v.x = v2.x;
                v.y = v2.y;
                v.z = v2.z;
                
          
                v2.x = fmod((1.31 * v.x + 0.14), 1);
                v2.y = fmod((1.32 * v.y + 0.15), 1);
                v2.z = fmod((1.38 * v.z + 0.15), 1);
                
                vertices[i*4].x = v.x * circleHeight/2;
                vertices[i*4].y = v.y * circleHeight/2;
                vertices[i*4].z = v.z * circleHeight/4;
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
        
        sphere.draw();
        
        if(randomm >Xin){
            text.unbind();
        }else{
            ((ofApp*)ofGetAppPtr())->black.unbind();
            ofPopStyle();
        }
        
        
        ofPopMatrix();
        
        
    }
    
    
    
    
};