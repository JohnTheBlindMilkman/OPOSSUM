#ifndef Analysis_h
    #define Analysis_h

    #include "Result.h"
    #include "../readers/UnigenReader.h"
    #include "../selection/ParticleSelector.h"

    template <typename T> class Analysis
    {
        public:
            Analysis(UnigenReader read, ParticleSelector seelctor);
            virtual ~Analysis() = default;

            Result DoAnalysis();

        private:
            void Init();
            void Next();
            void Finish();
            T fAnalysis;
            Result res;
    };

#endif