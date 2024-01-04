#if __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all typedefs;

#ifdef __MAKECINT__

#pragma link C++ namespace Opossum;
#pragma link C++ class Opossum::GenericResult + ;
#pragma link C++ class Opossum::EventMixer + ;
#pragma link C++ class Opossum::Analysis + ;
#pragma link C++ class Opossum::Analyser + ;
#pragma link C++ class Opossum::CF<Opossum::LCMS> + ;
#pragma link C++ class Opossum::CF1D<Opossum::LCMS> + ;
#pragma link C++ class Opossum::FemtoConstants + ;
#pragma link C++ class Opossum::LCMS + ;
#pragma link C++ class Opossum::TPIWeightGenerator + ;
#pragma link C++ class Opossum::WeightGenerator + ;
#pragma link C++ class Opossum::FemtoAnalysis + ;
#pragma link C++ class Opossum::QAAnalysis + ;
#pragma link C++ class Opossum::SpectraAnalysis + ;

#endif
#endif