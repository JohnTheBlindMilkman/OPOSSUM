#ifndef Analyser_h
    #define Analyser_h

    #include "Result.h"
    #include "Analysis.h"
    #include "../readers/UnigenReader.h"
    #include "../selection/ParticleSelector.h"

     class Analyser
    {
        public:
            Analyser(UnigenReader reader, ParticleSelector selector, Analysis analysis);
            virtual ~Analyser() = default;

            Result DoAnalysis();

        private:
            void Init();
            void Next();
            void Finish();

            UnigenReader fReader;
            ParticleSelector fSelector;
            Analysis fAnalysis;
            Result fResult;
    };

#endif