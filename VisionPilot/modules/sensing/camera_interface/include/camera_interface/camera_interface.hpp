#ifndef VISIONPILOT_CAMERA_INTERFACE_HPP
#define VISIONPILOT_CAMERA_INTERFACE_HPP
#include <string>
#include <tuple>
#include <vector>
#include <opencv2/core/mat.hpp>
#include <common/types.hpp>

namespace camera_interface
{
    class CameraInterface
    {
    public:
        virtual ~CameraInterface() = default;

        virtual bool is_device_open() const = 0;
        // {false, {}} = no frame yet (live) or stream ended (video, no loop).
        virtual std::tuple<bool, cv::Mat> get_latest_frame() = 0;
        virtual CameraStats get_camera_stats() const = 0;
    };
} // namespace camera_interface

#endif //VISIONPILOT_CAMERA_INTERFACE_HPP
