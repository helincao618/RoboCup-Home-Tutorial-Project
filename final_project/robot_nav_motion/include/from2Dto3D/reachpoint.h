// Generated by gencpp from file from2Dto3D/reachpoint.msg
// DO NOT EDIT!


#ifndef FROM2DTO3D_MESSAGE_REACHPOINT_H
#define FROM2DTO3D_MESSAGE_REACHPOINT_H

#include <ros/service_traits.h>


#include <from2Dto3D/reachpointRequest.h>
#include <from2Dto3D/reachpointResponse.h>


namespace from2Dto3D
{

struct reachpoint
{

typedef reachpointRequest Request;
typedef reachpointResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct reachpoint
} // namespace from2Dto3D


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::from2Dto3D::reachpoint > {
  static const char* value()
  {
    return "187b98ad08cccc689ad95612aaa15fa9";
  }

  static const char* value(const ::from2Dto3D::reachpoint&) { return value(); }
};

template<>
struct DataType< ::from2Dto3D::reachpoint > {
  static const char* value()
  {
    return "from2Dto3D/reachpoint";
  }

  static const char* value(const ::from2Dto3D::reachpoint&) { return value(); }
};


// service_traits::MD5Sum< ::from2Dto3D::reachpointRequest> should match 
// service_traits::MD5Sum< ::from2Dto3D::reachpoint > 
template<>
struct MD5Sum< ::from2Dto3D::reachpointRequest>
{
  static const char* value()
  {
    return MD5Sum< ::from2Dto3D::reachpoint >::value();
  }
  static const char* value(const ::from2Dto3D::reachpointRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::from2Dto3D::reachpointRequest> should match 
// service_traits::DataType< ::from2Dto3D::reachpoint > 
template<>
struct DataType< ::from2Dto3D::reachpointRequest>
{
  static const char* value()
  {
    return DataType< ::from2Dto3D::reachpoint >::value();
  }
  static const char* value(const ::from2Dto3D::reachpointRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::from2Dto3D::reachpointResponse> should match 
// service_traits::MD5Sum< ::from2Dto3D::reachpoint > 
template<>
struct MD5Sum< ::from2Dto3D::reachpointResponse>
{
  static const char* value()
  {
    return MD5Sum< ::from2Dto3D::reachpoint >::value();
  }
  static const char* value(const ::from2Dto3D::reachpointResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::from2Dto3D::reachpointResponse> should match 
// service_traits::DataType< ::from2Dto3D::reachpoint > 
template<>
struct DataType< ::from2Dto3D::reachpointResponse>
{
  static const char* value()
  {
    return DataType< ::from2Dto3D::reachpoint >::value();
  }
  static const char* value(const ::from2Dto3D::reachpointResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // FROM2DTO3D_MESSAGE_REACHPOINT_H