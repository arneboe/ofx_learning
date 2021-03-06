#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include <vector>
#include "Cat.hpp"



class App : public ofBaseApp
{
public:

    App();

    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
    void contactStart(ofxBox2dContactArgs& e);

private:

    ofxBox2d b2dWorld;
    ofxBox2dCircle mouse;
    b2MouseJoint* mouseJoint; //TODO how to discard this?
    std::vector<Cat> cats;
    
};
