#ifndef PARSER_H
#define PARSER_H

#include "Bar.h"
#include "Chart.h"
#include "NoteBuilder.h"
#include <pugixml.hpp>

enum ParserErrorStatus {
    PARSE_GP_ERR_UNZIP,
    PARSE_GP_ERR_SCORE_OPEN,
    PARSE_GP_ERR_SCORE_READ,
    PARSE_GP_SUCCESS
};

struct ParserError {
    ParserErrorStatus status;
    const char* message;
};

/* ------- Search Predicates ------- */

struct FindBarWithID {
    FindBarWithID(int p_barID) : barID(p_barID) {}
    int barID;
    bool operator()(pugi::xml_node node) const {
        return node.attribute("id").as_int() == barID;
    }
};

struct FindVoiceWithID {
    FindVoiceWithID(int p_voiceID) : voiceID(p_voiceID) {}
    int voiceID;
    bool operator()(pugi::xml_node node) const {
        return node.attribute("id").as_int() == voiceID;
    }
};

struct FindBeatWithID {
    FindBeatWithID(int p_beatID) : beatID(p_beatID) {}
    int beatID;
    bool operator()(pugi::xml_node node) const {
        return node.attribute("id").as_int() == beatID;
    }
};

struct FindRhythmWithID {
    FindRhythmWithID(int p_rhythmID) : rhythmID(p_rhythmID) {}
    int rhythmID;
    bool operator()(pugi::xml_node node) const {
        return node.attribute("id").as_int() == rhythmID;
    }
};

struct FindNoteWithID {
    FindNoteWithID(int p_noteID) : noteID(p_noteID) {}
    int noteID;
    bool operator()(pugi::xml_node node) const {
        return node.attribute("id").as_int() == noteID;
    }
};

class Parser {
  public:
    Parser();
    ~Parser();
    ParserError LoadScore(const char*);
    ParserError ParseXML();

    char* GetScoreData() { return scoreData; }

  private:
    ParserError parseError;
    char* scoreData;
    Chart* chart;
    pugi::xml_document scoreXML;
    pugi::xml_node gpifNode;
    NoteBuilder* noteBuilder;

    // Utility Functions
    std::vector<int> SplitIds(const char*);

    // Parser Functions
    TimeSig ParseTimeSig(const char*);
    Bar* ParseBar(int, TimeSig&);
    std::vector<Note*> ParseNotesForBeat(std::vector<int>, Rhythm&);
    Rhythm* ParseRhythm(int);
};

#endif
