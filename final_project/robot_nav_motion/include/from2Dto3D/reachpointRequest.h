// Generated by gencpp from file from2Dto3D/reachpointRequest.msg
// DO NOT EDIT!


#ifndef FROM2DTO3D_MESSAGE_REACHPOINTREQUEST_H
#define FROM2DTO3D_MESSAGE_REACHPOINTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace from2Dto3D
{
template <class ContainerAllocator>
struct reachpointRequest_
{
  typedef reachpointRequest_<ContainerAllocator> Type;

  reachpointRequest_()
    : req(0)  {
    }
  reachpointRequest_(const ContainerAllocator& _alloc)
    : req(0)  {
  (void)_alloc;
    }



   typedef int32_t _req_type;
  _req_type req;





  typedef boost::shared_ptr< ::from2Dto3D::reachpointRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::from2Dto3D::reachpointRequest_<ContainerAllocator> const> ConstPtr;

}; // struct reachpointRequest_

typedef ::from2Dto3D::reachpointRequest_<std::allocator<void> > reachpointRequest;

typedef boost::shared_ptr< ::from2Dto3D::reachpointRequest > reachpointRequestPtr;
typedef boost::shared_ptr< ::from2Dto3D::reachpointRequest const> reachpointRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::from2Dto3D::reachpointRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace from2Dto3D

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::from2Dto3D::reachpointRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::from2Dto3D::reachpointRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::from2Dto3D::reachpointRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "688ec893d5ff2cccc11b9bc8bc41109b";
  }

  static const char* value(const ::from2Dto3D::reachpointRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x688ec893d5ff2cccULL;
  static const uint64_t static_value2 = 0xc11b9bc8bc41109bULL;
};

template<class ContainerAllocator>
struct DataType< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "from2Dto3D/reachpointRequest";
  }

  static const char* value(const ::from2Dto3D::reachpointRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 req\n\
";
  }

  static const char* value(const ::from2Dto3D::reachpointRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.req);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct reachpointRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::from2Dto3D::reachpointRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::from2Dto3D::reachpointRequest_<ContainerAllocator>& v)
  {
    s << indent << "req: ";
    Printer<int32_t>::stream(s, indent + "  ", v.req);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FROM2DTO3D_MESSAGE_REACHPOINTREQUEST_H
