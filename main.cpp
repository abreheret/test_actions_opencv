#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Please provide a path to an image file.";
    return -1;
  }
  std::string filename = argv[1];
  cv::Mat image = cv::imread(filename, 1);
  if (!image.data) {
    std::cerr << "No image data read.";
    return -1;
  }
  cv::resize(image, image, cv::Size(), 0.2, 0.2, cv::INTER_AREA);
  cv::namedWindow("Your Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Your Image", image);

  cv::waitKey(0);
  return 0;
}
