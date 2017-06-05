/****************************************************************************\
 * Copyright (C) 2016 Scandy
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 \****************************************************************************/

// For distribution.

#ifndef Scandy_SensorFrameMetaData_h
#define Scandy_SensorFrameMetaData_h

#include <scandy/utilities/MetaData.h>

#include <scandy/utilities/Pose.h>

namespace scandy { namespace utilities {

/**
 * \brief SensorFrameMetaData describes necessary additional information for
 * using a SensorFrame that's created by a SensorDataStream.
 */
class SensorFrameMetaData : public MetaData {
public:
  friend class hiberlite::access;
  // The relative pose of the sensor that captured a SensorFrame to Scandy's
  // coordinates
  scandy::utilities::Pose initial_pose_offset;

  // The DeviceID of the camera that captured a SensorFrame
  DeviceID device_id;

  // The SensorID of the stream that captured a SensorFrame
  SensorID sensor_id;

  template<class Archive>
  void hibernate(Archive & ar)
  {
    ar & HIBERLITE_NVP(initial_pose_offset);
    ar & HIBERLITE_NVP(device_id);
    ar & HIBERLITE_NVP(sensor_id);

    MetaData::hibernate(ar);
  }
};

}}

#endif // Scandy_SensorFrameMetaData_h