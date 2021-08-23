#include "App.hpp"

App::App()
{
}

void App::setup()
{
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetWindowTitle("Ball Physics");
    ofSetBackgroundColor(ofColor::black);

    b2dWorld.init(60, 0, 9.81);
    b2dWorld.createBounds();

    for(int i = 0; i < 4; ++i)
    {
        cats.emplace_back(ofRandomWidth(), ofRandomHeight(), "/home/arne/3mbcatfmII.png", b2dWorld.getWorld());
    }
}

void App::update()
{
    b2dWorld.update();
    
    for(Cat& c : cats)
    {
        c.update(mouseX, mouseY, 15);
    }
}

void App::draw()
{
       
    ofNoFill();
    for(Cat& c : cats)
    {
        c.draw();
    }

    ofPushStyle();
    ofFill();
    ofSetColor(ofColor::magenta);
    ofCircle(mouseX, mouseY, 15);
    ofPopStyle();
   
}

void App::keyPressed(int key)
{
}

void App::keyReleased(int key)
{
}

void App::mouseMoved(int x, int y)
{    

}

void App::mouseDragged(int x, int y, int button)
{

}

void App::mousePressed(int x, int y, int button)
{

}

void App::mouseReleased(int x, int y, int button)
{
}

void App::mouseEntered(int x, int y)
{
}

void App::mouseExited(int x, int y)
{
}

void App::windowResized(int w, int h)
{
}

void App::gotMessage(ofMessage msg)
{
}

void App::dragEvent(ofDragInfo dragInfo)
{
}
