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
    b2dWorld.enableEvents();
    ofAddListener(b2dWorld.contactStartEvents, this, &App::contactStart);
    b2dWorld.createBounds();

    mouse.setPhysics(1, 0.5, 0.9);
    mouse.setup(b2dWorld.getWorld(), 20, 20, 30);
    b2MouseJointDef md;  
    md.bodyB = mouse.body;
    //mouse joint needs two bodys but we dont need the first one for mouse following, thus just use ground
    md.bodyA = b2dWorld.ground;
    md.target = b2Vec2(0, 0);
    md.maxForce = 1000.0f * mouse.body->GetMass();
    mouseJoint = (b2MouseJoint*)b2dWorld.getWorld()->CreateJoint(&md);

    for(int i = 0; i < 10; ++i)
    {
        cats.emplace_back(ofRandomWidth(), ofRandomHeight(), "/home/arne/3mbcatfmII.png", b2dWorld.getWorld());
    }
}

void App::update()
{
    b2Vec2 p = ofxBox2d::toB2d(mouseX, mouseY);
    mouseJoint->SetTarget(p);
    b2dWorld.update();
    
    for(Cat& c : cats)
    {
        c.update();
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
    mouse.draw();
    ofDrawLine(mouse.getPosition().x, mouse.getPosition().y, mouseX, mouseY);
    // ofCircle(mouseX, mouseY, 15);
    ofPopStyle();
   
}

void App::contactStart(ofxBox2dContactArgs& e)
{
    const b2Body* a = e.a->GetBody();
    const b2Body* b = e.b->GetBody();
    //ignore ground collisions
    if(a == b2dWorld.ground || b == b2dWorld.ground)
    {
        return;
    }

    // std::cout << "HIZ" << std::endl;
    //find the cat that has been hit
    for(Cat& c : cats)
    {
        if(c.getBody() == a || c.getBody() == b)
        {
            c.hit();
        }
    }
}

void App::keyPressed(int key)
{
    if(key == 't') ofToggleFullscreen();
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
