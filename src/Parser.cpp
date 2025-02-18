#include "Parser.h"
#include "Extractor.h"
#include "Note.h"
#include "NoteBuilder.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <string.h>
#include <zip.h>

Parser::Parser() {
    chart = new Chart();
    noteBuilder = new NoteBuilder();
}

ParserError Parser::LoadScore(const char* filename) {
    zip_error error;
    zip_error_init(&error);
    GP_EXTRACT_STATUS status;
    if ((status = Extractor::ExtractGP(filename, &scoreData, &error)) !=
        GP_EXTRACT_STATUS::GP_SUCCESS) {
        // Populate Parser Error
        parseError.status = (ParserErrorStatus)status;
        parseError.message = zip_error_strerror(&error);
    }

    parseError.status = PARSE_GP_SUCCESS;

    return parseError;
}

ParserError Parser::ParseXML() {
    pugi::xml_parse_result result =
        scoreXML.load_buffer(scoreData, strlen(scoreData));

    if (!result) {
        printf("Error: %s", result.description());
        parseError.status = PARSE_GP_ERR_SCORE_READ;
    }

    gpifNode = scoreXML.child("GPIF");
    std::vector<Bar*> bars;

    for (pugi::xml_node masterBar :
         gpifNode.child("MasterBars").children("MasterBar")) {
        /* Each master bar has multiple children bars.
         * They are each denoted by a corresponding ID that links to a bar node
         * further down the line.
         * Since all children bar IDs are stored as one string separated by
         * spaces, We need to split the ids to add them to our vector
         */
        auto idsText = masterBar.child("Bars").text().as_string();
        TimeSig timeSig =
            ParseTimeSig(masterBar.child("Time").text().as_string());
        for (int id : SplitIds(idsText)) {
        }
    }

    return parseError;
}

std::vector<int> Parser::SplitIds(const char* text) {
    std::vector<int> ids;
    std::stringstream ss(text);

    std::string t;

    while (ss >> t) {
        if (int id = atoi(t.c_str())) {
            ids.push_back(id);
        }
    }

    return ids;
}

TimeSig Parser::ParseTimeSig(const char* text) {
    TimeSig timeSig;
    std::stringstream ss(text);

    std::string t;

    // The time signatures are stored as text in the form num/denom
    char del = '/';

    while (getline(ss, t, del)) {
        if (timeSig.num != 0) {
            timeSig.denom = atoi(t.c_str());
        } else {
            timeSig.num = atoi(t.c_str());
        }
    }

    return timeSig;
}

Bar* Parser::ParseBar(int barID, TimeSig& timeSig) {
    pugi::xml_node barNode =
        gpifNode.child("Bars").find_child(FindBarWithID(barID));

    int voiceID;

    std::stringstream ss(barNode.text().as_string());

    std::string t;

    ss >> t;
    voiceID = atoi(t.c_str());

    pugi::xml_node voiceNode =
        gpifNode.child("Voices").find_child(FindVoiceWithID(voiceID));

    std::vector<int> beatIDs =
        SplitIds(voiceNode.child("Beats").text().as_string());

    std::vector<pugi::xml_node> beatNodes;

    for (int id : beatIDs) {
        beatNodes.push_back(
            gpifNode.child("Beats").find_child(FindBeatWithID(id)));
    }

    std::vector<Note*> notes;

    for (pugi::xml_node beatNode : beatNodes) {
        std::vector<int> noteIDs =
            SplitIds(beatNode.child("Notes").text().as_string());
        const int rhythmID = beatNode.child("Rhythm").attribute("ref").as_int();
    }

    return bar;
}

Rhythm* Parser::ParseRhythm(int rhythmID) {
    pugi::xml_node rhythmNode =
        gpifNode.child("Rhythms").find_child(FindRhythmWithID(rhythmID));

    Rhythm* rhythm;

    const char* noteVal = rhythmNode.child("NoteValue").text().as_string();

    if (strcmp(noteVal, "Whole")) {
        rhythm->baseVal = RHYTHM_WHOLE;
    } else if (strcmp(noteVal, "Half")) {
        rhythm->baseVal = RHYTHM_HALF;
    } else if (strcmp(noteVal, "Quarter")) {
        rhythm->baseVal = RHYTHM_QUARTER;
    } else if (strcmp(noteVal, "Eighth")) {
        rhythm->baseVal = RHYTHM_EIGHTH;
    } else if (strcmp(noteVal, "Sixteenth")) {
        rhythm->baseVal = RHYTHM_SIXTEENTH;
    } else {
        printf("Error Parsing Rhythm: Unknown Note Value: %s\n", noteVal);
    }

    if (auto augmentNode = rhythmNode.child("AugmentationDot")) {
        rhythm->dots = augmentNode.attribute("count").as_int();
    }
}

std::vector<Note*> Parser::ParseNotesForBeat(std::vector<int> noteIDs,
                                             Rhythm& rhythm) {
    std::vector<Note*> notes;

    for (int noteID : noteIDs) {
        noteBuilder->NewNote();
        pugi::xml_node noteNode =
            gpifNode.child("Notes").find_child(FindNoteWithID(noteID));
    }
}
