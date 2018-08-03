#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	string imgName("13.jpg");
	if (argc == 2) imgName = argv[1];
	Mat image;
    image = imread(imgName.c_str(), IMREAD_COLOR); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    int n = image.rows;
    int m = image.cols;
    Mat newImage;
    newImage= Mat::zeros(n, m, image.type());
    cout<<image.type()<<endl;
    for (int i=0;i<n;i++)
    	for (int j=0;j<m;j++)
    	{
    		Vec3f x = image.at<Vec3b>(i,j);
    		//printf("%f %f %f\n",x.val[0],x.val[1],x.val[2]);
    		if (i%2==1 && j%2==1)
    		{
				newImage.at<Vec3b>(i,j).val[0] = x.val[0];
				continue;
    		}
    		if (i%2==0 && j%2==0)
    		{
				newImage.at<Vec3b>(i,j).val[2] = x.val[2];
				continue;
    		}
			newImage.at<Vec3b>(i,j).val[1] = x.val[1];
    	}

    Mat finalImage; // 0 red 1 green 2 blue
    finalImage= Mat::zeros(n, m, image.type());
    for (int i=1;i<n-1;i++)
    	for (int j=1;j<m-1;j++)
    	{
    		Vec3f x = newImage.at<Vec3b>(i,j);
    		//printf("%f %f %f\n",x.val[0],x.val[1],x.val[2]);
    		if (i%2==1 && j%2==1)
    		{
				finalImage.at<Vec3b>(i,j).val[0] = x.val[0];

				finalImage.at<Vec3b>(i,j).val[1] = 
					newImage.at<Vec3b>(i-1,j).val[1] +
					newImage.at<Vec3b>(i,j-1).val[1] +
					newImage.at<Vec3b>(i+1,j).val[1] +
					newImage.at<Vec3b>(i,j+1).val[1];
				finalImage.at<Vec3b>(i,j).val[1] /= 4;

				finalImage.at<Vec3b>(i,j).val[2] = 
					newImage.at<Vec3b>(i+1,j+1).val[2] +
					newImage.at<Vec3b>(i+1,j-1).val[2] +
					newImage.at<Vec3b>(i-1,j+1).val[2] +
					newImage.at<Vec3b>(i-1,j-1).val[2];
				finalImage.at<Vec3b>(i,j).val[2] /= 4;
				continue;
    		}
    		if (i%2==0 && j%2==0)
    		{
				finalImage.at<Vec3b>(i,j).val[2] = x.val[2];
				finalImage.at<Vec3b>(i,j).val[1] = 
					newImage.at<Vec3b>(i-1,j).val[1] +
					newImage.at<Vec3b>(i,j-1).val[1] +
					newImage.at<Vec3b>(i+1,j).val[1] +
					newImage.at<Vec3b>(i,j+1).val[1];
				finalImage.at<Vec3b>(i,j).val[1] /= 4;

				finalImage.at<Vec3b>(i,j).val[0] = 
					newImage.at<Vec3b>(i+1,j+1).val[0] +
					newImage.at<Vec3b>(i+1,j-1).val[0] +
					newImage.at<Vec3b>(i-1,j+1).val[0] +
					newImage.at<Vec3b>(i-1,j-1).val[0];
				finalImage.at<Vec3b>(i,j).val[0] /= 4;
				continue;
    		}
			finalImage.at<Vec3b>(i,j).val[1] = x.val[1];
			finalImage.at<Vec3b>(i,j).val[0] = 
					newImage.at<Vec3b>(i-1,j).val[0] +
					newImage.at<Vec3b>(i,j-1).val[0] +
					newImage.at<Vec3b>(i+1,j).val[0] +
					newImage.at<Vec3b>(i,j+1).val[0];
			finalImage.at<Vec3b>(i,j).val[0] /= 2; 
		
			finalImage.at<Vec3b>(i,j).val[2] = 
					newImage.at<Vec3b>(i-1,j).val[2] +
					newImage.at<Vec3b>(i,j-1).val[2] +
					newImage.at<Vec3b>(i+1,j).val[2] +
					newImage.at<Vec3b>(i,j+1).val[2];
			finalImage.at<Vec3b>(i,j).val[2] /= 2;
    	}




    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    //imshow( "Display window", finalImage );                // Show our image inside it.
    imwrite("13_bayer_mix.jpg", finalImage);
    imwrite("13_bayer.jpg", newImage);
    //waitKey(0); // Wait for a keystroke in the window

	return 0;
}
