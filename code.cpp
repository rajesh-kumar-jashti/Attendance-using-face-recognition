#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");
	while (true)
	{
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.3, 5);
		if (faces.size() <= 0)
			cout << "Absent" << endl;
		else
			cout << "present" << endl;
		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 205,                             50), 3);
		putText(img, to_string(faces.size())+"face found",Point(10, 40),   FONT_HERSHEY_DUPLEX, 1, Scalar(255, 0, 0), 2);
		}
imshow("frame", img);
		waitKey(1);
	}
}
