#ifndef _Meteor_LIB_DEFINES_H_
#define _Meteor_LIB_DEFINES_H_
 
#if defined(_WIN32) 
#   if defined(Meteor_EXPORTS)
#       define METEOR_EXPORT __declspec(dllexport)
#   else
#       define METEOR_EXPORT __declspec(dllimport)
#   endif
#else
#   define METEOR_EXPORT
#endif

#endif