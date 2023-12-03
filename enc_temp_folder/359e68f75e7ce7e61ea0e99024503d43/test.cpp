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

int main() {
	VideoCapture video(0);
	Mat img;
	while (true) {
		video.read(img);
		imshow("Frame", img);
		waitKey(1);
	}
	return 0;
}
