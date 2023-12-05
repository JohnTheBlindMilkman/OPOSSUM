#if __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all typedefs;

#ifdef __MAKECINT__

#pragma link C++ namespace Opossum;
#pragma link C++ class Opossum::UnigenReader + ;
#pragma link C++ class Opossum::UnigenEventCandidate + ;
#pragma link C++ class Opossum::UnigenParticleCandidate + ;
#pragma link C++ class UEvent + ;
#pragma link C++ class UParticle + ;

#endif
#endif