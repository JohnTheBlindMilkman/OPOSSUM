/**
 * @file UnigenReader.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief Reader implementation to accept UNIGEN format. THIS IS CURRENTLY A BASE CLASS; IT SHOULD NOT BE A BASE CLASS
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UnigenReader_h
    #define UnigenReader_h

    #include "TChain.h"
    #include "TString.h"
    #include "UnigenEventCandidate.h"

    namespace Opossum
    {
        class UnigenReader
        {
            public:
                /**
                 * @brief Construct a new Unigen Reader object
                 * 
                 * @param inpDirPath 
                 * @param treeName 
                 * @param nFiles 
                 */
                UnigenReader(const TString &inpDirPath, const TString &treeName, const int &nFiles);
                /**
                 * @brief Destroy the Unigen Reader object
                 * 
                 */
                ~UnigenReader();

                /**
                 * @brief Initialise reader. Open files to be read.
                 * 
                 * @return std::size_t number of entries
                 */
                std::size_t InitReader();
                /**
                 * @brief Get the Next Event object. Return false if end of chain is reached, and true otherwise.
                 * 
                 * @param evtCand 
                 * @return true 
                 * @return false 
                 */
                bool GetNextEvent(UnigenEventCandidate &evtCand);
                /**
                 * @brief Close the reader.
                 * 
                 */
                void CloseReader();

            private:
                /**
                 * @brief Collect all .root files into a TChain object.
                 * 
                 * @param inpDirPath 
                 * @param nFiles 
                 * @return std::unique_ptr<TChain> 
                 */
                std::unique_ptr<TChain> ReadFiles(const TString &inpDirPath, const int &nFiles);

                std::unique_ptr<TChain> fFileChain;
                UEvent *fUniEvent;
                TString fInpDirPath, fTreeName, fInpFileNameBase;
                int fNumberOfFiles;
                long int fEntries, fCurrentEntry;
        };
    }

#endif