//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "TextDotEdgesModelSource.h"

TextDotEdgesModelSource::TextDotEdgesModelSource(std::shared_ptr<FileReader> reader) : reader(reader) {

}

TextDotEdgesModelSource::~TextDotEdgesModelSource() {

}

void TextDotEdgesModelSource::read_vertexes() {
    reader->getIn() >> n;
    for (size_t i = 0; i < n; ++i) {
        read_line_vertex();
    }
}

void TextDotEdgesModelSource::read_edges() {
    reader->getIn() >> n;
    for (size_t i = 0; i < n; ++i) {
        read_line_edge();
    }
}


void TextDotEdgesModelSource::read_line_vertex() {
    double x1, x2, x3;
    reader->getIn() >> x1 >> x2 >> x3;
    this->points.emplace_back(Point3dForm(x1, x2, x3));
}


void TextDotEdgesModelSource::read_line_edge() {
    EdgeData line{};
    int x1, x2;
    reader->getIn() >> x1 >> x2;
    edges.emplace_back(std::pair<int, int>(x1, x2));
}
