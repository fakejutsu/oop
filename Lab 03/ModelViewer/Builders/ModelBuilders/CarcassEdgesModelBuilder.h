//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSEDGESMODELBUILDER_H
#define MODELVIEWER_CARCASSEDGESMODELBUILDER_H


#include "CarcassModelBuilder.h"
#include "TextEdgesModelSource.h"
#include "CarcassEdgesDataImplementor.h"
#include "FileReader.h"
#include <memory>

class CarcassEdgesModelBuilder : public CarcassModelBuilder {
public:
    explicit CarcassEdgesModelBuilder(std::shared_ptr<FileReader> reader);
    virtual ~CarcassEdgesModelBuilder();
    virtual void buildEdges() override;
    virtual void buildVertex() override;
    virtual std::shared_ptr<CarcassModelEntity> getModel() override;
protected:
    int state = 0;
    std::shared_ptr<std::vector<EdgeData>> edges;
    std::shared_ptr<TextEdgesModelSource> src;
};


#endif //MODELVIEWER_CARCASSEDGESMODELBUILDER_H
