#ifndef EDGEDATAITERATOR_H
#define EDGEDATAITERATOR_H

#include "edgedata.h"
#include <iterator>

class EdgeDataIterator
{

    using iterator_category = std::forward_iterator_tag;
    using value_type = EdgeData;
    using difference_type = EdgeData;
    using pointer = EdgeData*;
    using reference = EdgeData&;

public:
    EdgeDataIterator();
};

#endif // EDGEDATAITERATOR_H
