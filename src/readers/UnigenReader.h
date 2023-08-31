#ifndef UnigenReader_h
    #define UnigenReader_h

    #include "TChain.h"
    #include "TString.h"
    #include "UnigenEventCandidate.h"

    class UnigenReader
    {
        public:
            UnigenReader(const TString &inpDirPath, const TString &treeName, const int &nFiles);
            ~UnigenReader();

            void InitReader();
            bool GetNextEvent(UnigenEventCandidate &evtCand);
            void CloseReader();

        private:
            std::unique_ptr<TChain> ReadFiles(const TString &inpDirPath, const int &nFiles);

            std::unique_ptr<TChain> fFileChain;
            UEvent *fUniEvent;
            TString fInpDirPath, fTreeName, fInpFileNameBase;
            int fNumberOfFiles;
            long int fEntries, fCurrentEntry;
    };

#endif