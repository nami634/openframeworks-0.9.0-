#pragma once

#include "ofMain.h"
#include "ofxMultiKinectV2.h"

#define STRINGIFY(x) #x

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxMultiKinectV2 kinect;
    ofTexture texture;
    ofEasyCam ecam;
    ofVboMesh mesh;
    ofShader irShader;
};

static string irFragmentShader =
STRINGIFY(
          uniform sampler2DRect tex;
          void main()
          {
              vec4 col = texture2DRect(tex, gl_TexCoord[0].xy);
              float value = col.r / 65535.0;
              //　float value = col.r / 4500.0;　irのデフォルト値は大きすぎるから調整必要！！ (4500がベスト）
              gl_FragColor = vec4(vec3(value), 1.0);
          }
          );