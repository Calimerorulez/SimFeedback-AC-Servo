#ifndef _PLUGIN_OBJECTS_HPP_
#define _PLUGIN_OBJECTS_HPP_


// rF currently uses 4-byte packing ... whatever the current packing is will
// be restored at the end of this include with another #pragma.
#pragma pack( push, 4 )


//旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
//� types of plugins                                                       �
//읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸

enum PluginObjectType
{
  PO_INVALID      = -1,
  //-------------------
  PO_GAMESTATS    =  0,
  PO_NCPLUGIN     =  1,
  PO_IVIBE        =  2,
  PO_INTERNALS    =  3,
  PO_RFONLINE     =  4,
  //-------------------
  PO_MAXIMUM
};


//旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
//�  PluginObject                                                          �
//�    - interface used by plugin classes.                                 �
//읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸

class PluginObject
{
 private:

  class PluginInfo *mInfo;             // used by main executable to obtain info about the plugin that implements this object

 public:

  void SetInfo( class PluginInfo *p )  { mInfo = p; }        // used by main executable
  class PluginInfo *GetInfo() const    { return( mInfo ); }  // used by main executable
  class PluginInfo *GetInfo()          { return( mInfo ); }  // used by main executable
};


//旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
//� typedefs for dll functions - easier to use a typedef than to type      �
//� out the crazy syntax for declaring and casting function pointers       �
//읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸

typedef const char *      ( __cdecl *GETPLUGINNAME )();
typedef PluginObjectType  ( __cdecl *GETPLUGINTYPE )();
typedef int               ( __cdecl *GETPLUGINVERSION )();
typedef PluginObject *    ( __cdecl *CREATEPLUGINOBJECT )();
typedef void              ( __cdecl *DESTROYPLUGINOBJECT )( PluginObject *obj );


//旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
//읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸

// See #pragma at top of file
#pragma pack( pop )

#endif // _PLUGIN_OBJECTS_HPP_

