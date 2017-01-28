#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <sstream>

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

using namespace dlib;
using namespace std;

// ----------------------------------------------------------------------------------------

int main(int argc, char** argv) {  
	try {
		if (argc == 1) {
			cout << "Give one image file as argument to this program." << endl;
			cout << "This error should not be happening if you are using a web app." << endl;
			return 0;
		}

		double adjust_threshold = 0;
		if(argc == 3)
			adjust_threshold = atof(argv[2]);
		
		frontal_face_detector detector = get_frontal_face_detector();
		ifstream fin("object_detector.svm", ios::binary);
		deserialize(detector, fin);

		array2d<unsigned char> img;
		load_image(img, argv[1]);
		
		// Now tell the face detector to give us a list of bounding boxes
		// around all the eyes it can find in the image.
		std::vector<rectangle> dets = detector(img, adjust_threshold);

		std::string ret("[");
		for(int i = 0; i < dets.size(); ++i) {
			ret += std::string("{ \"left\":") + to_string(dets[i].left()) + std::string(", \"top\":") + to_string(dets[i].top()) + std::string(", \"width\":") + to_string(dets[i].width()) + std::string(", \"height\":") + to_string(dets[i].height()) + std::string("}");
			if(i < dets.size() - 1)
				ret += ", ";
		}
		
		ret += std::string("]");
		cout << ret << endl;
		//		cout << dets[0].left() << "," << dets[0].top() << "," << dets[0].width() << "," << dets[0].height() << endl;
		//}
		
	}
	catch (exception& e) {
		cout << "\nexception thrown!" << endl;
		cout << e.what() << endl;
	}
}

// ----------------------------------------------------------------------------------------

