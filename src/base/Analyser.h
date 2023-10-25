/**
 * @file Analyser.h
 * @author Jedrzej Kolas (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief 
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef Analyser_h
    #define Analyser_h

    #include "Result.h"
    #include "Analysis.h"
    #include "../readers/UnigenReader.h"
    #include "../selection/ParticleSelector.h"
    #include "../readers/UnigenEventCandidate.h"

    class Analyser
    {
        public:
            /**
             * @brief Construct a new Analyser object
             * 
             * @param analysis Any analysis object, e.g. FemtoAnalysis or SpectraAnalysis
             * @param selector Particle selector object
             * @param inpDirPath Path to the inpud directory storing input .root files
             * @param treeName The name of the TTree inside input .root files
             * @param nFiles Number of input .root files to be analysed
             */
            Analyser(const Analysis analysis, const ParticleSelector &selector, const TString &inpDirPath, const TString &treeName, const int &nFiles);
            virtual ~Analyser() = default;

            /**
             * @brief Perform the chosen analysis process (defined by the constructor parameters)
             * 
             * @param threads number of threads to be used in parallelisation of the analysis (1 means no parallelisation, >1 is parallelised on given amount of threads), currently not implemented
             * @return Result 
             */
            Result DoAnalysis(int threads = 1);

        private:
            void Init();
            bool Next();
            void Finish();

            UnigenReader fReader;
            ParticleSelector fSelector;
            UnigenEventCandidate fEvtCand;
            Analysis fAnalysis;
            Result fResult;
            bool fDoNext;
    };

#endif