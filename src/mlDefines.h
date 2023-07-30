/*
 * File: mlDefines.h
 * Author: @matiaslanzi
 * 
 * All the settings are defined here. (shold probably move to preferences)
 * TODO: create preferences. 
 */

#ifndef MLDEFINES_H
#define MLDEFINES_H

// Debug?
#define DEBUG

// Basic settings
#define MLFRAMES_PER_SECOND 60
#define MLFRAME_RATE        1000/MLFRAMES_PER_SECOND

#define MLWINDOW_TITLE      "Little Engine"
#define MLWINDOW_WIDTH      320
#define MLWINDOW_HEIGHT     240
#define MLRENDERSCALEX      3
#define MLRENDERSCALEY      3

#define MLFONTFILE          "Chicago.ttf"
#define MLFONTSIZE          9

// Game
#define MLPLAYER_SHOTS_AVAILABLE 10
#define MLENEMY_COLUMNS 8
#define MLENEMY_ROWS 8

#ifdef DEBUG
//#define trace(...)                         printf( __VA_ARGS__ )
#define trace(...)                              SDL_Log( __VA_ARGS__ )
//#define nstrace(...)                       printf( "%s", [[NSString stringWithFormat:__VA_ARGS__] UTF8String] )
// #define traceFrame( comment, a )           (printf( comment #a ".frame: (%0.2f, %0.2f) (%0.2f, %0.2f)\n", a.frame.origin.x, a.frame.origin.y, a.frame.size.width, a.frame.size.height ))
// #define traceFrameCenter( comment, a )     (printf( comment #a ".frame: (%0.2f, %0.2f) (%0.2f, %0.2f) center: [%0.2f, %0.2f]\n", a.frame.origin.x, a.frame.origin.y, a.frame.size.width, a.frame.size.height, a.center.x, a.center.y ))
// #define traceFrameCenterObj( comment, a )  (printf( comment #a ".frame: (%0.2f, %0.2f) (%0.2f, %0.2f) center: [%0.2f, %0.2f] class: %s\n", a.frame.origin.x, a.frame.origin.y, a.frame.size.width, a.frame.size.height, a.center.x, a.center.y, [[[a class] description] UTF8String] ))
// #define traceBounds( comment, a )          (printf( comment #a ".bounds: (%0.2f, %0.2f) (%0.2f, %0.2f)\n", a.bounds.origin.x, a.bounds.origin.y, a.bounds.size.width, a.bounds.size.height ))
// #define traceBoundsCenter( comment, a )    (printf( comment #a ".bounds: (%0.2f, %0.2f) (%0.2f, %0.2f) center: [%0.2f, %0.2f]\n", a.bounds.origin.x, a.bounds.origin.y, a.bounds.size.width, a.bounds.size.height, a.center.x, a.center.y ))
// #define traceBoundsCenterObj( comment, a ) (printf( comment #a ".bounds: (%0.2f, %0.2f) (%0.2f, %0.2f) center: [%0.2f, %0.2f] class: %s\n", a.bounds.origin.x, a.bounds.origin.y, a.bounds.size.width, a.bounds.size.height, a.center.x, a.center.y, [[[a class] description] UTF8String] ))
// #define traceCenter( comment, a )          (printf( comment #a ".center: (%0.2f, %0.2f)\n", a.center.x, a.center.y ))
#else
#define trace(...)
//#define nstrace(...)
// #define traceFrame( comment, a ) 
// #define traceFrameCenter( comment, a ) 
// #define traceFrameCenterObj( comment, a )
// #define traceBounds( comment, a )
// #define traceBoundsCenter( comment, a )
// #define traceBoundsCenterObj( comment, a )
// #define traceCenter( comment, a )
#endif

#define degrees2rad( a ) ((M_PI /180) * a)      // Make this a const, avoid #fines

#endif /* MLDEFINES_H */