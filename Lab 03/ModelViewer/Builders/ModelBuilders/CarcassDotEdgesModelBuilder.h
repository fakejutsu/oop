//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_CARCASSDOTEDGESMODELBUILDER_H
#define MODELVIEWER_CARCASSDOTEDGESMODELBUILDER_H

#include "CarcassModelBuilder.h"
#include "FileReader.h"
#include "TextDotEdgesModelSource.h"

class CarcassDotEdgesModelBuilder : public CarcassModelBuilder {
public:
    explicit CarcassDotEdgesModelBuilder(std::shared_ptr<FileReader> reader);
    virtual ~CarcassDotEdgesModelBuilder();
    virtual void buildEdges() override;
    virtual void buildVertex() override;
    virtual std::shared_ptr<CarcassModelEntity> getModel() override;
protected:
    int state = 0;
    std::shared_ptr<std::vector<std::pair<int, int>>> edges{};
    std::shared_ptr<std::vector<Point3dForm>> points {};
    std::shared_ptr<TextDotEdgesModelSource> source;
};

#endif //MODELVIEWER_CARCASSDOTEDGESMODELBUILDER_H
