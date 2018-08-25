/**
 * @brief A header file with declaration for StandardCamera class
 * @file standard_camera.h
 */

#ifndef OPENVINO_PIPELINE_LIB_STANDARD_CAMERA_H
#define OPENVINO_PIPELINE_LIB_STANDARD_CAMERA_H

#include "openvino_service/inputs/base_input.h"

#include <opencv2/opencv.hpp>

namespace Input {
class StandardCamera : public BaseInputDevice {
 public:
  StandardCamera() = default;
  ~StandardCamera() override = default;
  bool initialize() override;
  bool initialize(int t) override;
  bool initialize(size_t width, size_t height) override;
  bool read(cv::Mat *frame) override;
  void config() override;

 private:
  cv::VideoCapture cap;
};
}
#endif //OPENVINO_PIPELINE_LIB_STANDARD_CAMERA_H
