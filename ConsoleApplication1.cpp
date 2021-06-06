#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace cv;
using namespace std;

void Print_Vector(vector<int> Vec)
{
	for (int i = 0; i < Vec.size(); i++) {
		cout << Vec[i] << " ";
	}
	cout << endl;
	return;
}

int main(int argc, char** argv)
{
	//cout << "hello1" << endl;

	// Read the image file
	Mat img = imread("C:/Users/purva/Pictures/img.jpg");
	Mat image = img; //creating an identical copy
	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return -1;
	}
	else {
		cout << "file open" << endl;
	}
	set<vector<int>>s;

	cout << image.rows << " " << image.cols << endl; //original size
	resize(img, img, Size(200, 200));
	cout << img.rows << " " << img.cols << endl; // size after resizing

	//scanning the resized image
	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			// get pixel
			Vec3b& color = img.at<Vec3b>(y, x);
			int a, b, c;
			a = (int)color[2];
			b = (int)color[1];
			c = (int)color[0];
			s.insert({ a,b,c });

			//cout << (int)color[0] << " " << (int)color[1] << " " << (int)color[2] << endl;
			// ... do something to the color ....
			/*color[0] = 13;
			color[1] = 0;
			color[2] = 15;*/
			// set pixel
			//image.at<Vec3b>(Point(x,y)) = color;
			
		}
	}

	//Printing only unique rgb values
	cout << "set " << endl;
	for (auto it = s.begin(); it != s.end(); it++) 
		Print_Vector(*it);
	

	String windowName = "hello "; //Name of the window
	namedWindow(windowName); // Create a window
	imshow(windowName, img); // Show our image inside the created window.
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow(windowName); //destroy the created window

	return 0;
}