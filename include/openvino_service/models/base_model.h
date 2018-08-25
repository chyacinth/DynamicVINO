/**
 * @brief A header file with declaration for BaseModel Class
 * @file base_model.h
 */

#ifndef OPENVINO_PIPELINE_LIB_BASE_MODEL_H
#define OPENVINO_PIPELINE_LIB_BASE_MODEL_H

#include <vector>

#include "inference_engine.hpp"

namespace Engines {
  class Engine;
}

namespace Models {
/**
 * @class BaseModel
 * @brief This class represents the network given by .xml and .bin file
 */
class BaseModel {
  using Ptr = std::shared_ptr<BaseModel>;
 public:
  /**
   * @brief Initialize the class with given .xml, .bin and .labels file. It will
   * also check whether the number of input and output are fit.
   * @param[in] model_loc The location of model' s .xml file
   * (model' s bin file should be the same as .xml file except for extension)
   * @param[in] input_num The number of input the network should have.
   * @param[in] output_num The number of output the network should have.
   * @param[in] batch_size The number of batch size the network should have.
   * @return Whether the input device is successfully turned on.
   */
  BaseModel(
      const std::string &model_loc,
      int input_num, int output_num, int batch_size);
  virtual ~BaseModel() = default;
  /**
   * @brief Get the label vector.
   * @return The label vector.
   */
  inline std::vector<std::string> &getLabels() { return labels_; }
  /**
   * @brief Get the maximum batch size of the model.
   * @return The maximum batch size of the model.
   */
  inline const int getMaxBatchSize() const { return max_batch_size_;}
  /**
   * @brief Initialize the model. During the process the class will check
   * the network input, output size, check layer property and
   * set layer property.
   */
  void modelInit();
  /**
   * @brief Get the name of the model.
   * @return The name of the model.
   */
  virtual const std::string getModelName() const = 0;

 protected:
  /**
   * @brief Check whether the layer property
   * (output layer name, output layer type, etc.) is right
   * @param[in] network_reader The reader of the network to be checked.
   */
  virtual void checkLayerProperty(
      const InferenceEngine::CNNNetReader::Ptr& network_reader) = 0;
  virtual void
  /**
   * @brief Set the layer property (layer layout, layer precision, etc.).
   * @param[in] network_reader The reader of the network to be set.
   */
  setLayerProperty(InferenceEngine::CNNNetReader::Ptr network_reader) = 0;
 private:
  friend class Engines::Engine;

  void checkNetworkSize(int, int, InferenceEngine::CNNNetReader::Ptr);
  InferenceEngine::CNNNetReader::Ptr net_reader_;
  std::vector<std::string> labels_;
  int input_num_;
  int output_num_;
  int max_batch_size_;
  std::string model_loc_;
};

}

#endif //OPENVINO_PIPELINE_LIB_BASE_MODEL_H
