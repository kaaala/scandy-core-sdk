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

#ifndef Scandy_IMUFrameMetaData_h
#define Scandy_IMUFrameMetaData_h

#include <scandy/utilities/SensorFrameMetaData.h>


namespace scandy { namespace utilities {

/**
 * \brief IMUFrameMetaData contains information related to the IMU sensors an
 * IMU frame was generated by
 */
class IMUFrameMetaData : public SensorFrameMetaData {
public:
  friend class hiberlite::access;
  // TODO sensor noise quantified in some way
  float sensor_error;

  template<class Archive>
  void hibernate(Archive & ar)
  {
    ar & HIBERLITE_NVP(sensor_error);

    SensorFrameMetaData::hibernate(ar);
  }
};

}}

#endif // Scandy_IMUFrameMetaData_h