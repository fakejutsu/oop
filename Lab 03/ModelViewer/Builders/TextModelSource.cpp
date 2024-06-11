//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "TextEdgesModelSource.h"


TextEdgesModelSource::TextEdgesModelSource(std::shared_ptr<FileReader> fileReader) : reader(fileReader) {

}

TextEdgesModelSource::~TextEdgesModelSource() {

}

void TextEdgesModelSource::read_edges() {
    size_t n;
    reader->getIn() >> n;
    for (size_t i = 0; i < n; ++i) {
        read_line();
    }
}


void TextEdgesModelSource::read_line() {
    EdgeData line{};
    double x1, x2, x3;
    reader->getIn() >> x1 >> x2 >> x3;
    line.first = Point4dForm(x1, x2, x3, 1);

    reader->getIn() >> x1 >> x2 >> x3;
    line.second = Point4dForm(x1, x2, x3, 1);

    edges.emplace_back(line);
}
