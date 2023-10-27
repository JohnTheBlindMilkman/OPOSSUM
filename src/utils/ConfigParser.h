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

    #include <map>
    #include "TString.h"
    #include "json.hpp"

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
            ConfigParser(TString configFile);
            /**
             * @brief Destroy the Config Parser object
             * 
             */
            ~ConfigParser();

            /**
             * @brief Read the selection.json file and check its contens.
             * 
             * @return true - file exists;
             * @return false - otherwise
             */
            bool ReadSelection() const;

            /**
             * @brief Read the cutMapping.json file.
             * 
             * @return true - file exists;
             * @return false - otherwise
             */
            bool ReadCutMapping() const;
            
        private:
            /**
             * @brief Print to the standard output the cuts of selection.json file which did are not known
             * 
             */
            void PrintUnknownParameters() const;

            nlohmann::json fJSONfile;
    };
    


#endif