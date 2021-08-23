#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include <vector>

using Circle = ofxBox2dCircle;
using CirclePtr = std::shared_ptr<Circle>;



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

private:

    ofxBox2d b2dWorld;
    //need to use pointers because b2d stuff breaks on copy/move...
    std::vector<CirclePtr> circles;
    std::vector<double> rots;
    ofImage catImg;
    ofSoundPlayer miau;
    const double mouseRadius = 15.0;
    
};
