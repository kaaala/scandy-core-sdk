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

/**
 * \file CameraIntrinsics.h
 * \brief Furnishes class for `CameraIntrinsics`.
 */

#ifndef Scandy_CameraIntrinsics_h
#define Scandy_CameraIntrinsics_h

#include <scandy/utilities/vector_types.h>

namespace scandy { namespace utilities {

/**
 * \class CameraIntrinsics
 * \brief Defines all the necesary definitions Scandy Core needs.
 */
class CameraIntrinsics {
public:
  /** resolution width */
  int m_width;

  /** resolution height */
  int m_height;

  /** focal length along x direction */
  double m_fx;

  /** focal lenght along y direction */
  double m_fy;

  /** Image center x */
  double m_cx;

  /** Image center y */
  double m_cy;

  /** 1st radial distortion coefficient */
  double m_k1;

  /** 2nd radial distortion coefficient */
  double m_k2;

  /** 1st tangential distortion coefficient */
  double m_p1;

  /** 2nd tangential distortion coeeficient */
  double m_p2;

  /** 3rd radial distortion coefficient (optional) */
  double m_k3;

  /** 4th radial distortion coefficient (optional) */
  double m_k4;

  template <class Archive>
  void serialize(Archive& archive){
    archive(
      m_width,
      m_height,
      m_fx,
      m_fy,
      m_cx,
      m_cy,
      m_k1,
      m_k2,
      m_p1,
      m_p2,
      m_k3,
      m_k4
    );
  }

public:
  CameraIntrinsics();
  CameraIntrinsics(const CameraIntrinsics&) = default;
  CameraIntrinsics(CameraIntrinsics&&) = default;
  CameraIntrinsics& operator=(const CameraIntrinsics&) = default;
  CameraIntrinsics& operator=(CameraIntrinsics&) = default;
  CameraIntrinsics& operator=(CameraIntrinsics&&) = default;

  CameraIntrinsics(
    int width,
    int height,
    double fx,
    double fy,
    double cx,
    double cy,
    double k1,
    double k2,
    double p1,
    double p2,
    double k3,
    double k4
  );

  CameraIntrinsics& operator *=(double d){
    m_width *= d;
    m_height *= d;
    m_fx *= d;
    m_fy *= d;
    m_cx *= d;
    m_cy *= d;
    return *this;
  }
  CameraIntrinsics& operator /=(double d){
    return operator*=(1./d);
  }
  CameraIntrinsics operator*(double d){
    CameraIntrinsics k(*this);
    k *= d;
    return k;
  }
  CameraIntrinsics operator/(double d){
    CameraIntrinsics k(*this);
    k /= d;
    return k;
  }

  /**
   * Create intrinsics based on relative pose and the intrinsics of an analogous point cloud.
   * Preconditions:
   * - m_width and m_height have already been set correctly
   * - The analogous intrinsic matrix is based on a relative pose
   *   with rotation part equal to EXIF Orientation 1 relative to this frame.
   *   (That is, if the original analogous intrinsics did not have a relative pose rotation of
   *    "no rotation", they have  already been corrected based on their relative pose.)
   * @param rel_pose             The relative pose to scale and transform from
   * @param analogous_intrinsics The CameraIntrinsics we should be analogous to
   */
  void scaleAndTransform(scandy::utilities::Mat4f rel_pose, CameraIntrinsics analogous_intrinsics);
};

}}

#endif /**  Scandy_CameraIntrinsics_h */
