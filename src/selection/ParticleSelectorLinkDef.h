#if __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all typedefs;

#ifdef __MAKECINT__

#pragma link C++ namespace Opossum;
#pragma link C++ class Opossum::ParticleSelector + ;
#pragma link C++ class Opossum::EventCandidate + ;
#pragma link C++ class Opossum::TrackCandidate + ;
#pragma link C++ class Opossum::GenericCandidate < Opossum::TrackObservable> + ;
#pragma link C++ class Opossum::GenericCandidate < Opossum::EventObservable> + ;
#pragma link C++ class Opossum::GenericCandidate < Opossum::PairObservable> + ;

#endif
#endif