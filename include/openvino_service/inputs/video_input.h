/**
 * @brief A header file with declaration for Video class
 * @file video_input.h
 */

#ifndef OPENVINO_PIPELINE_LIB_VIDEO_INPUT_H
#define OPENVINO_PIPELINE_LIB_VIDEO_INPUT_H

#include "openvino_service/inputs/base_input.h"

#include <opencv2/opencv.hpp>

namespace Input {
class Video : public BaseInputDevice {
 public:
  explicit Video(const std::string &);
  ~Video() override = default;
  bool initialize() override;
  bool initialize(int t) override { return initialize(); };
  bool initialize(size_t width, size_t height) override;
  bool read(cv::Mat *frame) override;
  void config() override;

 private:
  cv::VideoCapture cap;
  std::string video_;
};
}

#endif //OPENVINO_PIPELINE_LIB_VIDEO_INPUT_H
