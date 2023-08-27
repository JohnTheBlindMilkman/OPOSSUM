#if __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all typedefs;

#ifdef __MAKECINT__

#pragma link C++ class ParticleSelector + ;
#pragma link C++ class EventCandidate + ;
#pragma link C++ class TrackCandidate + ;
#pragma link C++ class TrackCut + ;
#pragma link C++ class EventCut + ;
#pragma link C++ class PairCut + ;
#pragma link C++ class JJTrackCut + ;
#pragma link C++ class JJEventCut + ;

#endif
#endif