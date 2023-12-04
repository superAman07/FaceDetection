#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/*int main() {
	string path = "D:/users/ASUS/Codes/openCV Project with C++/opencv/build/x64/vc16/lib/download.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
	return 0;
}*/

void main() {
	VideoCapture video(0);// we can put any video by its path...
	//VideoCapture video("C:/Users/ASUS/Pictures/Camera Roll/WIN_20230621_07_38_51_Pro.mp4");
	Mat img;

	CascadeClassifier facedetect;
	
	facedetect.load("haarcascade_frontalface_default.xml");
	
	while (true) {
		video.read(img);

		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);
		cout << faces.size() << "\n";
		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255),3);
			rectangle(img, Point(0,0), Point(200,35), Scalar(50, 50, 255), 100);
			putText(img, to_string(faces.size())+ " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}

		imshow("Frame", img);
		waitKey(1);

	}
}
