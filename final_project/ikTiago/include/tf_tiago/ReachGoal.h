// Generated by gencpp from file tf_tiago/ReachGoal.msg
// DO NOT EDIT!


#ifndef TF_TIAGO_MESSAGE_REACHGOAL_H
#define TF_TIAGO_MESSAGE_REACHGOAL_H

#include <ros/service_traits.h>


#include <tf_tiago/ReachGoalRequest.h>
#include <tf_tiago/ReachGoalResponse.h>


namespace tf_tiago
{

struct ReachGoal
{

typedef ReachGoalRequest Request;
typedef ReachGoalResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReachGoal
} // namespace tf_tiago


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::tf_tiago::ReachGoal > {
  static const char* value()
  {
    return "172c1930e2eae19890d6e9b43691f21a";
  }

  static const char* value(const ::tf_tiago::ReachGoal&) { return value(); }
};

template<>
struct DataType< ::tf_tiago::ReachGoal > {
  static const char* value()
  {
    return "tf_tiago/ReachGoal";
  }

  static const char* value(const ::tf_tiago::ReachGoal&) { return value(); }
};


// service_traits::MD5Sum< ::tf_tiago::ReachGoalRequest> should match 
// service_traits::MD5Sum< ::tf_tiago::ReachGoal > 
template<>
struct MD5Sum< ::tf_tiago::ReachGoalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::tf_tiago::ReachGoal >::value();
  }
  static const char* value(const ::tf_tiago::ReachGoalRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::tf_tiago::ReachGoalRequest> should match 
// service_traits::DataType< ::tf_tiago::ReachGoal > 
template<>
struct DataType< ::tf_tiago::ReachGoalRequest>
{
  static const char* value()
  {
    return DataType< ::tf_tiago::ReachGoal >::value();
  }
  static const char* value(const ::tf_tiago::ReachGoalRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::tf_tiago::ReachGoalResponse> should match 
// service_traits::MD5Sum< ::tf_tiago::ReachGoal > 
template<>
struct MD5Sum< ::tf_tiago::ReachGoalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::tf_tiago::ReachGoal >::value();
  }
  static const char* value(const ::tf_tiago::ReachGoalResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::tf_tiago::ReachGoalResponse> should match 
// service_traits::DataType< ::tf_tiago::ReachGoal > 
template<>
struct DataType< ::tf_tiago::ReachGoalResponse>
{
  static const char* value()
  {
    return DataType< ::tf_tiago::ReachGoal >::value();
  }
  static const char* value(const ::tf_tiago::ReachGoalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TF_TIAGO_MESSAGE_REACHGOAL_H
