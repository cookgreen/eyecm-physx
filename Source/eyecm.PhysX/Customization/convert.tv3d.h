//=============================+=====================================+=
//                              tv3d conversion file
//=============================+=====================================+=
//=============================+=====================================+=
//                              Vector3
//=============================+=====================================+=
inline NxVec3                   ToNx(Vector3 v)
  {
    return NxVec3( v.x, v.y, v.z );
  }

//=============================+=====================================+=
inline Vector3                  FromNx(const NxVec3& v)
  {
    Vector3 result;

    result.x = v.x;
    result.y = v.y;
    result.z = v.z;

    return result;
  }

//=============================+=====================================+=
inline void                     ToNx(Vector3 v, float& x, float& y, float& z)
  {
    x = v.x; y = v.y; z = v.z;
  }

//=============================+=====================================+=
//                              AxisAlignedBox
//=============================+=====================================+=
inline NxBounds3                ToNx(AxisAlignedBox v)
  {
    NxBounds3 result;

    result.set( v.Lower.x, v.Lower.y, v.Lower.z, v.Upper.x, v.Upper.y, v.Upper.z );

    return result;
  }

//=============================+=====================================+=
inline AxisAlignedBox           FromNx(NxBounds3& v)
  {
    return AxisAlignedBox( FromNx( v.min ), FromNx( v.max ) );
  }

//=============================+=====================================+=
//                              Matrix4x4
//=============================+=====================================+=
inline NxMat34                  ToNx(Matrix4x4 m)
  {
    NxMat34 result( false );

    result.setColumnMajor44( &m.m11 );

    return result;
  }

//=============================+=====================================+=
inline Matrix4x4                FromNx(const NxMat34& m)
  {
    Matrix4x4 result;

    m.getColumnMajor44( &result.m11 );

    return result;
  }


//=============================+=====================================+=
//                              Matrix3x3
//=============================+=====================================+=
inline NxMat33                  ToNx(Matrix3x3 m)
  {
    NxMat33 result;
    result.setColumnMajor( &m.m11 );
    return result;
  }

//=============================+=====================================+=
inline Matrix3x3                FromNx(const NxMat33& m)
  {
    Matrix3x3 result;
    m.getColumnMajor( &result.m11 );
    return result;
  }


//=============================+=====================================+=
//                              Quaternion
//=============================+=====================================+=
inline NxQuat                   ToNx(Quaternion q)
  {
    NxQuat result;
    //
    result.setWXYZ( q.w, q.x, q.y, q.z );
    //
    return result;
  }

//=============================+=====================================+=
inline Quaternion               FromNx(const NxQuat& q)
  {
    Quaternion result;
    //
    result.x = q.x;
    result.y = q.y;
    result.z = q.z;
    result.w = q.w;
    //
    return result;
  }

//=============================+=====================================+=
//                              OrientedBox
//=============================+=====================================+=
inline NxBox                    ToNx(OrientedBox v)
  {
    return NxBox( ToNx( v.Center ), ToNx( v.Dimension ) / 2.0, ToNx( v.Orientation ) );
  }

//=============================+=====================================+=
inline OrientedBox              FromNx(const NxBox& v)
  {
    OrientedBox result;

    result.Orientation = FromNx( v.rot );
    result.Center      = FromNx( v.center );
    result.Dimension   = FromNx( v.extents * 2 );

    return result;
  }


//=============================+=====================================+=
//                              Sphere
//=============================+=====================================+=
inline NxSphere                 ToNx(Sphere v)
  {
    return NxSphere( ToNx( v.Center ), v.Radius );
  }

//=============================+=====================================+=
inline Sphere                   FromNx(const NxSphere& v)
  {
    return Sphere( FromNx( v.center ), v.radius );
  }


//=============================+=====================================+=
//                              Plane
//=============================+=====================================+=
inline Plane                    FromNx(const NxPlane& v)
  {
    return Plane( FromNx( v.normal ), v.d );
  }

//=============================+=====================================+=
inline NxPlane                  ToNx(Plane v)
  {
    return NxPlane( ToNx( v.Normal ), v.Dist );
  }


//=============================+=====================================+=
//                              Line
//=============================+=====================================+=
inline NxRay                    ToNx(Line v)
  {
    NxVec3 dn = ToNx( v.Direction );
    dn.normalize();
    return NxRay( ToNx( v.Origin ), dn );
  }

//=============================+=====================================+=
inline Line                     FromNx(const NxRay& v)
  {
    return Line( FromNx( v.orig ), FromNx( v.dir ) );
  }


//=============================+=====================================+=
//                              Capsule
//=============================+=====================================+=
inline NxCapsule                ToNx(Capsule v)
  {
    return NxCapsule( NxSegment( ToNx( v.a ), ToNx( v.b ) ), v.Radius );
  }

//=============================+=====================================+=
inline Capsule                  FromNx(const NxCapsule& v)
  {
    return Capsule( FromNx( v.p0 ), FromNx( v.p1 ), v.radius );
  }


//=============================+=====================================+=
//                              Triangle
//=============================+=====================================+=
inline NxTriangle               ToNx(Triangle v)
  {
    return NxTriangle( ToNx( v.a ), ToNx( v.b ), ToNx( v.c ) );
  }

//=============================+=====================================+=
inline Triangle                 FromNx(const NxTriangle& v)
  {
    return Triangle( FromNx( v.verts[0] ), FromNx( v.verts[1] ), FromNx( v.verts[2] ) );
  }
