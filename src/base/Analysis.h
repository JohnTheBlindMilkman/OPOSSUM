#ifndef Analysis_h
    #define Analysis_h

    #include "Result.h"
    #include "../readers/UnigenReader.h"
    #include "../selection/ParticleSelector.h"

    template <typename T> class Analysis
    {
        public:
            Analysis(UnigenReader read, ParticleSelector seelctor);
            ~Analysis();

            Result DoAnalysis();

        private:
            T fAnalysis;
            Result res;
    };

#endif