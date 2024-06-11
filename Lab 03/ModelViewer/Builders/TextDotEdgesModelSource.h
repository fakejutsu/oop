//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_TEXTDOTEDGESMODELSOURCE_H
#define MODELVIEWER_TEXTDOTEDGESMODELSOURCE_H

#include <fstream>

#include "AbsCorrectModelSource.h"
#include "FileReader.h"

class TextDotEdgesModelSource : public AbsCarcassModelSource {
public:
    explicit TextDotEdgesModelSource(std::shared_ptr<FileReader> reader);

    ~TextDotEdgesModelSource();

    std::vector<EdgeData> && getEdges() override { return std::vector<EdgeData>(0);}
    std::vector<Point3dForm> && getVertexes() override { read_vertexes(); return std::move(points);}
    virtual std::vector<std::pair<int, int>>&& getEdgesIdPairs() override {read_edges(); return std::move(edges);};
private:
    int n = 0;
    std::vector<std::pair<int, int>> edges{};
    std::vector<Point3dForm> points {};
    std::shared_ptr<FileReader> reader;
    void read_edges();

    void read_vertexes();

    void read_line_vertex();
    void read_line_edge();
};


#endif //MODELVIEWER_TEXTDOTEDGESMODELSOURCE_H
