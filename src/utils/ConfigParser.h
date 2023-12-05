/**
 * @file ConfigParser.h
 * @author Jędrzej Kołaś (jedrzej.kolas.dokt@pw.edu.pl)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ConfigParser_h
    #define ConfigParser_h

    #include <unordered_map>
    #include <fstream>
    #include <iostream>
    #include "CutParser.h"
    #include "json.hpp"

    namespace Opossum
    {
        struct ParticleSelectorInfo
        {
            std::optional<std::unordered_map<EventObservable,CutEntry> > eventCutSet;
            std::optional<std::unordered_map<TrackObservable,CutEntry> > trackCutSet;
            std::optional<std::unordered_map<PairObservable,CutEntry> > pairCutSet;
        };

        struct GenericReaderInfo
        {
            std::string eventDirPath;
            std::string eventKey;
            uint filesToLoad;
            std::string selectionFilePath;
        };
        
        void from_json(const nlohmann::json &j, GenericReaderInfo &g);
        
        class ConfigParser
        {
            public:
                /**
                 * @brief Construct a new Config Parser object
                 * 
                 */
                ConfigParser();
                /**
                 * @brief Construct a new Config Parser object and initialise the lookup table of cuts. Read the config .json file.
                 * 
                 * @param configFile .json configuration file
                 */
                ConfigParser(std::string configFile);
                /**
                 * @brief Destroy the Config Parser object
                 * 
                 */
                ~ConfigParser();
                /**
                 * @brief Getter for cut maps for ParticleSelector class
                 * 
                 * @return ParticleSelectorInfo 
                 */
                ParticleSelectorInfo PassSelectionInformation() const;
                /**
                 * @brief Getter for parameters to GenericReader
                 * 
                 * @return GenericReaderInfo 
                 */
                GenericReaderInfo PassGenericReaderInformation() const;
                
            private:
                /**
                 * @brief Read the selection.json file and check its contens.
                 * 
                 * @return true - file exists;
                 * @return false - otherwise
                 */
                bool ReadSelection();
                void InitCutLists();

                CutParser fCutParser;
                ParticleSelectorInfo fPSInfo;
                GenericReaderInfo fGRInfo;
                std::ifstream fSelectionFile, fConfigFile;
                nlohmann::json fJSONselection;
                std::array<const std::string,3> fCutTypeName;
                std::unordered_map<EventObservable,CutEntry> fEventCutList;
                std::unordered_map<TrackObservable,CutEntry> fTrackCutList;
                std::unordered_map<PairObservable,CutEntry> fPairCutList;
        };

        inline ParticleSelectorInfo ConfigParser::PassSelectionInformation() const {return fPSInfo;}
        inline GenericReaderInfo ConfigParser::PassGenericReaderInformation() const {return fGRInfo;}
    }    


#endif