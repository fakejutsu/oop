//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_TEXTEDGESMODELSOURCE_H
#define MODELVIEWER_TEXTEDGESMODELSOURCE_H

#include <fstream>

#include "AbsCorrectModelSource.h"
#include "FileReader.h"


class TextEdgesModelSource : public AbsCarcassModelSource {
public:
    explicit TextEdgesModelSource(std::shared_ptr<FileReader> reader);
    ~TextEdgesModelSource();
    std::vector<EdgeData> && getEdges() override { read_edges(); return std::move(edges);}
    std::vector<Point3dForm> && getVertexes() override { return std::vector<Point3dForm>(0);}
    virtual std::vector<std::pair<int, int>>&& getEdgesIdPairs() override {return std::vector<std::pair<int, int>>(0);};

private:
    std::vector<EdgeData> edges{};
    std::shared_ptr<FileReader> reader;
    void read_edges();
    void read_line();
};


#endif //MODELVIEWER_TEXTEDGESMODELSOURCE_H
