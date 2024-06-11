//
// Created by Кирилл Воробьев on 10.06.2024.
//

#ifndef MODELVIEWER_SIMPLECOMPOSITEOBJECT_H
#define MODELVIEWER_SIMPLECOMPOSITEOBJECT_H

#include "CompositeSceneObject.h"

#include <vector>

class SimpleCompositeObject : public CompositeSceneObject {
public:
    using SimpleObjectCollection = std::vector<std::shared_ptr<SceneObject>>;

    SimpleCompositeObject(SimpleObjectCollection &objects);
    virtual ~SimpleCompositeObject() override = default;

    virtual void addObjectToComposite(std::shared_ptr<SceneObject>) override;
    virtual void removeObjectFromComposite(std::shared_ptr<SceneObject>) override;

    virtual void accept(VisitorBase &v) override;

    virtual std::string objectName() override;

    virtual ComposiIterator begin() override;
    virtual ComposiIterator end() override;

protected:
    std::shared_ptr<SimpleObjectCollection> collection;
};


#endif //MODELVIEWER_SIMPLECOMPOSITEOBJECT_H
