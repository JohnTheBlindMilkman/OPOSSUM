#include "ConfigParser.h"

namespace Opossum
{
    void from_json(const nlohmann::json &j, GenericReaderInfo &g)
    {
        g.eventDirPath = j["eventDir"].get<std::string>();
        g.eventKey = j["eventKey"].get<std::string>();
        g.filesToLoad = j["numberOfFiles"].get<uint>();
        g.selectionFilePath = j["selectionFilePath"].get<std::string>();
    }

    ConfigParser::ConfigParser(/* args */)
    {
    }

    ConfigParser::ConfigParser(std::string configFile) : fCutParser(), fConfigFile(configFile), fCutTypeName({"eventCut","trackCut","pairCut"})
    {
        if (fConfigFile.is_open())
        {
            try
            {
                nlohmann::json data = nlohmann::json::parse(fConfigFile);
                fGRInfo = data.get<GenericReaderInfo>();
                ReadSelection();
                
            }
            catch(nlohmann::json::parse_error &ex)
            {
                std::cerr << "ConfigParser::ReadSelection - parse error at byte " << ex.byte << std::endl;
            }
            fConfigFile.close();
        }
        else
            std::cout << "Did not find" << configFile << std::endl;
    }

    ConfigParser::~ConfigParser()
    {
    }

    bool ConfigParser::ReadSelection()
    {
        fSelectionFile = std::ifstream(fGRInfo.selectionFilePath);

        if(fSelectionFile.is_open())
        {
            try
            {
                fJSONselection = nlohmann::json::parse(fSelectionFile);
                InitCutLists();
            }
            catch(nlohmann::json::parse_error &ex)
            {
                std::cerr << "ConfigParser::ReadSelection - parse error at byte " << ex.byte << std::endl;
                return false;
            }
            fSelectionFile.close();
            return true;
        }
        else
            std::cout << "Did not find " << fGRInfo.selectionFilePath << std::endl;

        return false;
    }

    // yes, this is ugly and unreadable
    void ConfigParser::InitCutLists()
    {
        if (fJSONselection.contains(fCutTypeName.at(0)))
            fPSInfo.eventCutSet = fCutParser.ConvertFromJson<EventObservable>(fJSONselection.at(fCutTypeName.at(0)),fCutTypeName.at(0));
        else
            fPSInfo.eventCutSet = std::nullopt;

        if (fJSONselection.contains(fCutTypeName.at(1)))
            fPSInfo.trackCutSet = fCutParser.ConvertFromJson<TrackObservable>(fJSONselection.at(fCutTypeName.at(1)),fCutTypeName.at(1));
        else
            fPSInfo.trackCutSet = std::nullopt;

        if (fJSONselection.contains(fCutTypeName.at(2)))
            fPSInfo.pairCutSet = fCutParser.ConvertFromJson<PairObservable>(fJSONselection.at(fCutTypeName.at(2)),fCutTypeName.at(2));
        else
            fPSInfo.pairCutSet = std::nullopt;
    }
}