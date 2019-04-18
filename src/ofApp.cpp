#include "ofApp.h"
#include <vector> 
#include <list>

void ofApp::setup()
{
    std::string file = "example.json";
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << result.getRawString();
    } else {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }

	for (Json::ArrayIndex i = 0; i < result["circles"].size(); ++i)
	{
		std::vector<double> circlesData;
		circlesData.push_back(result["circles"][i]["radius"].asDouble());
		circlesData.push_back(result["circles"][i]["color"].asDouble());
		for (auto t : result["circles"][i]["times"]) {
			circlesData.push_back(t.asDouble());
		}
		circles.push_back(circlesData);
	}
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetHexColor(0x00FF00);
    std::stringstream ss;
	
	for (auto timeList : circles) {
		for (auto t : timeList) {
			ss << t << ", ";
		}
		ss << "\n";
	}

	ofDrawBitmapString(ss.str(), 10, 14);
}
